// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  RunAwayTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "RunAwayTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const runaway_spec[] =
#else
static const char* runaway_spec[] =
#endif
  {
    "implementation_id", "RunAwayTest",
    "type_name",         "RunAwayTest",
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
RunAwayTest::RunAwayTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_LRFOut("LRF", m_LRF),
    m_barcodeOut("barcode", m_barcode),
    m_outIn("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RunAwayTest::~RunAwayTest()
{
}



RTC::ReturnCode_t RunAwayTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("out", m_outIn);
  
  // Set OutPort buffer
  addOutPort("LRF", m_LRFOut);
  addOutPort("barcode", m_barcodeOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RunAwayTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t RunAwayTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAwayTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t RunAwayTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RunAwayTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RunAwayTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t RunAwayTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAwayTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAwayTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAwayTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RunAwayTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool RunAwayTest::runTest()
{
    return true;
}


extern "C"
{
 
  void RunAwayTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(runaway_spec);
    manager->registerFactory(profile,
                             RTC::Create<RunAwayTest>,
                             RTC::Delete<RunAwayTest>);
  }
  
}
