/*!
 *  @file scpi_rp_acq_trigger.h
 *
 *  This is a library for interacting with Red Pitaya boards via SCPI server
 *
 *
 *  Written by Red Pitaya Industries.
 *
 *  MIT license, all text above must be included in any redistribution
 */

#ifndef SCPI_RP_ACQ_TRIGGER_H
#define SCPI_RP_ACQ_TRIGGER_H

#include <stdint.h>

#include "acq/acq_enums.h"
#include "common/base_io.h"

namespace scpi_rp {
/*!
 *  Class that stores state and functions for SCPI server
 */
class SCPIAcqTrigger {
 public:
  SCPIAcqTrigger(){};
  ~SCPIAcqTrigger(){};

  /*!
   *  Set acquisition trigger source. The options are disabled, trigger
   *  immediately, or set trigger source & edge.
   *  @param trigger Trigger source.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool trigger(EACQTrigger trigger);

  /*!
   *  Set acquisition trigger source. The options are disabled, trigger
   *  immediately, or set trigger source & edge. Used only in split trigger mode
   *  @param channel Fast ADC channel
   *  @param trigger Trigger source.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool triggerCh(EACQChannel channel, EACQTrigger trigger);

  /*!
   *  Get acquisition trigger status. If the trigger is DISABLED or the
   *  acquisition is triggered, the state is True. Otherwise, it is False.
   *  @param state Trigger state (true = triggered or disabled, false =
   * waiting).
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool stateQ(bool *state);

  /*!
   *  Get acquisition trigger status. If the trigger is DISABLED or the
   *  acquisition is triggered, the state is True. Otherwise, it is False. Used
   *  only in split trigger mode.
   *  @param channel Fast ADC channel
   *  @param state Trigger state (true = triggered or disabled, false =
   * waiting).
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool stateChQ(EACQChannel channel, bool *state);

  /*!
   *  Get acquisition trigger status with internal timeout handling.
   *  @param timeout_ms Timeout in milliseconds.
   *  @param state Trigger state:
   *         - ACQ_TR_OK (0) - Trigger occurred successfully
   *         - ACQ_TR_TIMEOUT (1) - Timeout elapsed without trigger
   *         - ACQ_TR_ERROR (2) - Error occurred
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool stateIntQ(int timeout_ms, EACQIntTrigger *state);

  /*!
   *  Get acquisition trigger status with internal timeout handling for a
   * specific channel. Used only in split trigger mode.
   *  @param channel Fast ADC channel
   *  @param timeout_ms Timeout in milliseconds.
   *  @param state Trigger state:
   *         - ACQ_TR_OK (0) - Trigger occurred successfully
   *         - ACQ_TR_TIMEOUT (1) - Timeout elapsed without trigger
   *         - ACQ_TR_ERROR (2) - Error occurred
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool stateIntChQ(EACQChannel channel, int timeout_ms, EACQIntTrigger *state);

  /*!
   *  Returns True if the buffer is full of data. Otherwise returns False.
   *  @param state Fill state (true = buffer full, false = not full).
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool fillQ(bool *state);

  /*!
   *  Returns True if the buffer is full of data. Otherwise returns False. Used
   *  only in split trigger mode.
   *  @param channel Fast ADC channel
   *  @param state Fill state (true = buffer full, false = not full).
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool fillChQ(EACQChannel channel, bool *state);

  /*!
   *  Returns the buffer fill status with timeout handling.
   *  @param timeout_ms Timeout in milliseconds.
   *  @param state Fill state:
   *         - ACQ_TR_OK (0) - Buffer filled successfully
   *         - ACQ_TR_TIMEOUT (1) - Timeout elapsed without buffer fill
   *         - ACQ_TR_ERROR (2) - Error occurred
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool fillIntQ(int timeout_ms, EACQIntTrigger *state);

  /*!
   *  Returns the buffer fill status with timeout handling for a specific
   * channel. Used only in split trigger mode (currently only STEMlab 125-14
   * 4-Input)
   *  @param channel Fast ADC channel
   *  @param timeout_ms Timeout in milliseconds.
   *  @param state Fill state:
   *         - ACQ_TR_OK (0) - Buffer filled successfully
   *         - ACQ_TR_TIMEOUT (1) - Timeout elapsed without buffer fill
   *         - ACQ_TR_ERROR (2) - Error occurred
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool fillIntChQ(EACQChannel channel, int timeout_ms, EACQIntTrigger *state);

  /*!
   *  Set the trigger delay in samples. The triggering moment is by default in
   *  the middle of acquired buffer (at 8192th sample) (trigger delay set to 0).
   *  Total samples: 8192 + delay
   *  @param value Number of samples.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool delay(int value);

  /*!
   *  Set the trigger delay in samples. The triggering moment is by default in
   *  the middle of acquired buffer (at 8192th sample) (trigger delay set to 0).
   *  Used only in split trigger mode.
   *  Total samples: 8192 + delay
   *  @param channel Fast ADC channel
   *  @param value Number of samples.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool delayCh(EACQChannel channel, int value);

  /*!
   *  Get the trigger delay in samples.
   *  @param value Number of samples.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool delayQ(int *value);

  /*!
   *  Get the trigger delay in samples. Used only in split trigger mode.
   *  @param channel Fast ADC channel
   *  @param value Number of samples.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool delayChQ(EACQChannel channel, int *value);

  /*!
   *  Set the trigger hysteresis threshold value in Volts.
   *  @param value Hysteresis value in Volts.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool hysteresis(float value);

  /*!
   *  Get the trigger hysteresis threshold value in Volts.
   *  @param value Return hysteresis value in Volts.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool hysteresisQ(float *value);

  /*!
   *  Set the trigger level in Volts.
   *  @param value Trigger level in Volts.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool level(float value);

  /*!
   *  Get the trigger level in Volts.
   *  @param value Return trigger level in Volts.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool levelQ(float *value);

  /*!
   *  Set the trigger level in Volts for a specific channel. Used only in split
   * trigger mode.
   *  @param channel Fast ADC channel
   *  @param value Trigger level in Volts.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool levelCh(EACQChannel channel, float value);

  /*!
   *  Get the trigger level in Volts for a specific channel. Used only in split
   * trigger mode.
   *  @param channel Fast ADC channel
   *  @param value Return trigger level in Volts.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool levelChQ(EACQChannel channel, float *value);

  /*!
   *  Set the external trigger level in Volts. (Only SIGNALlab 250-12)
   *  @param value Trigger level in Volts.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool levelExternal(float value);

  /*!
   *  Get the external trigger level in Volts. (Only SIGNALlab 250-12)
   *  @param value Return trigger level in Volts.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool levelExternalQ(float *value);

  /*!
   *  Set the external trigger acquisition debouncer in microseconds (value must
   *  be positive).
   *  @param value Debouncer time in microseconds.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool debouncer(double value);

  /*!
   *  Get the external trigger acquisition debouncer in microseconds
   *  @param value Return debouncer time in microseconds.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool debouncerQ(double *value);

  /*!
   *  Initialize the acquisition timestamp counter with a specific value.
   *  Sets the initial value for the timestamp counter used in acquisition
   *  triggering and data capture.
   *  @param value Initial timestamp value.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool initTimeStamp(uint64_t value);

  /*!
   *  Get the acquisition timestamp for a specific channel.
   *  Retrieves the timestamp value associated with the trigger event or
   *  data capture for the specified channel.
   *  @param channel Fast ADC channel
   *  @param value Return timestamp value in nanoseconds.
   *  @return Returns true if the command was called successfully, returns false
   * for any other problems.
   */
  bool timeStampQ(EACQChannel channel, uint64_t *value);

  /*!
   * Returns the number of valid data points (samples) in the buffer that were
   * captured before the trigger event occurred. This value indicates how many
   * samples are available in the pre-trigger portion of the buffer.
   *
   * @param value Pointer to uint32_t where the pre-trigger sample count will
   *        be stored.
   * @return Returns true if the command was called successfully, returns false
   *         for any other problems.
   */
  bool preTriggerCounterQ(uint32_t *value);

  /*!
   * Returns the number of valid data points (samples) in the buffer before the
   * trigger position for the specified channel. This channel-separated version
   * works with FPGA support for split trigger mode.
   *
   * @param channel The analog input channel:
   *        - RP_CH_1 (IN1) or RP_CH_3 for 4-input models
   *        - RP_CH_2 (IN2) or RP_CH_4 for 4-input models
   * @param value Pointer to uint32_t where the pre-trigger sample count for the
   *        specified channel will be stored.
   * @return Returns true if the command was called successfully, returns false
   *         for any other problems.
   */
  bool preTriggerCounterChQ(EACQChannel channel, uint32_t *value);

  friend class SCPIRedPitaya;

 private:
  void setInterface(BaseIO *io);
  BaseIO *m_io = nullptr;
};

}  // namespace scpi_rp

#endif