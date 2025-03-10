/*!
 *  @file SCPI_RP.cpp
 *
 *  This is a library for interacting with Red Pitaya boards via SCPI server
 *
 *
 *  Written by Red Pitaya Industries.
 *
 *  MIT license, all text above must be included in any redistribution
 */

#include "SCPI_RP.h"

#include "common/base_io.h"
#include "uart/uart_scpi.h"

using namespace scpi_rp;

BaseIO *g_base_io = nullptr;

SCPIRedPitaya::SCPIRedPitaya() {}

SCPIRedPitaya::~SCPIRedPitaya() { delete g_base_io; }

void SCPIRedPitaya::initStream(Stream *serial) {
  UARTInterface *u = new UARTInterface();
  u->init(serial);
  g_base_io = u;
  system.setInterface(u);
  dio.setInterface(u);
  aio.setInterface(u);
  daisy.setInterface(u);
  pll.setInterface(u);
  system_led.setInterface(u);
  gen.setInterface(u);
  acq.control.setInterface(u);
  acq.settings.setInterface(u);
  acq.data.setInterface(u);
  acq.trigger.setInterface(u);
  acq.dma.settings.setInterface(u);
  acq.dma.data.setInterface(u);
}