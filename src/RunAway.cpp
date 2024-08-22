// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  RunAway.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include "RunAway.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const runaway_spec[] =
#else
static const char* runaway_spec[] =
#endif
  {
    "implementation_id", "RunAway",
    "type_name",         "RunAway",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
RunAway::RunAway(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_LRFIn("LRF", m_LRF),
    m_barcodeIn("barcode", m_barcode),
    m_outOut("out", m_out)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RunAway::~RunAway()
{
}



RTC::ReturnCode_t RunAway::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("LRF", m_LRFIn);
  addInPort("barcode", m_barcodeIn);
  
  // Set OutPort buffer
  addOutPort("out", m_outOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RunAway::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t RunAway::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAway::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t RunAway::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RunAway::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RunAway::onExecute(RTC::UniqueId /*ec_id*/)
{
    if (m_barcodeIn.isNew()) {
        m_barcodeIn.read();
        if (m_LRFIn.isNew()) {
            m_LRFIn.read();
            if (m_barcode.data == 404) {  //バーコードが検出できていない
                if (m_LRF.data == 0) {  //LRFからのデータが0なら左回転(右回転)
                    m_out.data.vx = 0;
                    m_out.data.va = -1.0;
                }
                else if (m_LRF.data == 1) {  //LRFからのデータが1なら前進(後退)
                    m_out.data.vx = -0.5;
                    m_out.data.va = 0;
                }
                else if (m_LRF.data == 2) {  //LRFからのデータが2なら右回転(左回転)
                    m_out.data.vx = 0;
                    m_out.data.va = 1.0;
                }
                else if (m_LRF.data == 3) {  //LRFからのデータが3なら後退(前進)
                    m_out.data.vx = 0.5;
                    m_out.data.va = 0;
                }
                else {
                    m_out.data.vx = 0;
                    m_out.data.va = 0;
                }
            }
            else {
                m_out.data.vx = 0;
                m_out.data.va = 0;
            }
            m_out.data.vy = 0;
            m_outOut.write();
        }
    }
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t RunAway::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAway::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAway::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAway::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAway::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void RunAwayInit(RTC::Manager* manager)
  {
    coil::Properties profile(runaway_spec);
    manager->registerFactory(profile,
                             RTC::Create<RunAway>,
                             RTC::Delete<RunAway>);
  }
  
}
