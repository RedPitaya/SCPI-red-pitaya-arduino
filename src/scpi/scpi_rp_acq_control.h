/*!
 *  @file scpi_rp_acq_control.h
 *
 *  This is a library for interacting with Red Pitaya boards via SCPI server
 *
 *
 *  Written by Red Pitaya Industries.
 *
 *  MIT license, all text above must be included in any redistribution
 */

#ifndef SCPI_RP_ACQ_CONTROL_H
#define SCPI_RP_ACQ_CONTROL_H

#include <stdint.h>

#include "acq/acq_enums.h"
#include "common/base_io.h"

namespace scpi_rp {
/*!
 *  Class that stores state and functions for SCPI server
 */
class SCPIAcqControl {
 public:
  SCPIAcqControl(){};
  ~SCPIAcqControl(){};

  /*!
   *  Start the acquisition.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool start();

  /*!
   *  Start the acquisition. Used only in split trigger mode
   *  @param channel In channel
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool startCh(EACQChannel channel);

  /*!
   *  Stop the acquisition.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool stop();

  /*!
   *  Stop the acquisition. Used only in split trigger mode
   *  @param channel In channel
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool stopCh(EACQChannel channel);

  /*!
   *  Stop the acquisition and reset all acquisition parameters to default
   *  values.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool reset();

  /*!
   *  Stop the acquisition and reset all acquisition parameters to default
   *  values. Used only in split trigger mode
   *  @param channel In channel
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool resetCh(EACQChannel channel);

  /*!
   *  Enables split trigger mode.
   *  @param enable Enable or disable split trigger
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool splitTriggerMode(bool enable);

  /*!
   *  Returns the split trigger mode status
   *  @param enable Return split trigger
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool splitTriggerModeQ(bool *enable);

  /*!
   * Enables continuous acquisition mode where the buffer continues to fill
   * even after a trigger event has occurred. When enabled (true), the
   * acquisition does not stop at trigger and continuously overwrites the
   * buffer. When disabled (false), acquisition stops after trigger and buffer
   * is frozen.
   *
   * @param enable Enable or disable ARM keep mode:
   *        - true: Continuous acquisition after trigger (buffer keeps filling)
   *        - false: Stop acquisition after trigger (buffer frozen)
   * @return Returns true if the command was called successfully, returns false
   *         for any other problems.
   */
  bool keepArm(bool enable);

  /*!
   * Returns the current status of the ARM keep mode.
   * When enabled, acquisition continues after trigger and the buffer is
   * continuously overwritten. When disabled, acquisition stops at trigger
   * and the buffer contains only data up to the trigger event.
   *
   * @param enable Pointer to bool where the current ARM keep mode status
   *        will be stored:
   *        - true: Continuous acquisition after trigger is enabled
   *        - false: Continuous acquisition after trigger is disabled
   * @return Returns true if the command was called successfully, returns false
   *         for any other problems.
   */
  bool keepArmQ(bool *enable);

  friend class SCPIRedPitaya;

 private:
  void setInterface(BaseIO *io);
  BaseIO *m_io = nullptr;
};

}  // namespace scpi_rp

#endif
