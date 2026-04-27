#include "acq_trigger.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace scpi_rp;

bool scpi_rp::setAcqTrigger(BaseIO *io, EACQTrigger trigger) {
  constexpr char cmd[] = "ACQ:TRig ";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }

  if (trigger == ACQ_DISABLED) {
    constexpr char param[] = "DISABLED\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_NOW) {
    constexpr char param[] = "NOW\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH1_PE) {
    constexpr char param[] = "CH1_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH1_NE) {
    constexpr char param[] = "CH1_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH2_PE) {
    constexpr char param[] = "CH2_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH2_NE) {
    constexpr char param[] = "CH2_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_EXT_PE) {
    constexpr char param[] = "EXT_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_EXT_NE) {
    constexpr char param[] = "EXT_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_AWG_PE) {
    constexpr char param[] = "AWG_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_AWG_NE) {
    constexpr char param[] = "AWG_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH3_PE) {
    constexpr char param[] = "CH3_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH3_NE) {
    constexpr char param[] = "CH3_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH4_PE) {
    constexpr char param[] = "CH4_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH4_NE) {
    constexpr char param[] = "CH4_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH1_AE) {
    constexpr char param[] = "CH1_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH2_AE) {
    constexpr char param[] = "CH2_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_EXT_AE) {
    constexpr char param[] = "EXT_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_AWG_AE) {
    constexpr char param[] = "AWG_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH3_AE) {
    constexpr char param[] = "CH3_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH4_AE) {
    constexpr char param[] = "CH4_AE\r\n";
    return io->writeStr(param);
  }

  io->writeCommandSeparator();
  return false;
}

bool scpi_rp::setAcqTriggerCh(BaseIO *io, EACQChannel channel,
                              EACQTrigger trigger) {
  constexpr char cmd[] = "ACQ:TRig:CH";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }

  if (trigger == ACQ_DISABLED) {
    constexpr char param[] = " DISABLED\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_NOW) {
    constexpr char param[] = " NOW\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH1_PE) {
    constexpr char param[] = " CH1_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH1_NE) {
    constexpr char param[] = " CH1_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH2_PE) {
    constexpr char param[] = " CH2_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH2_NE) {
    constexpr char param[] = " CH2_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_EXT_PE) {
    constexpr char param[] = " EXT_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_EXT_NE) {
    constexpr char param[] = " EXT_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_AWG_PE) {
    constexpr char param[] = " AWG_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_AWG_NE) {
    constexpr char param[] = " AWG_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH3_PE) {
    constexpr char param[] = " CH3_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH3_NE) {
    constexpr char param[] = " CH3_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH4_PE) {
    constexpr char param[] = " CH4_PE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH4_NE) {
    constexpr char param[] = " CH4_NE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH1_AE) {
    constexpr char param[] = " CH1_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH2_AE) {
    constexpr char param[] = " CH2_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_EXT_AE) {
    constexpr char param[] = " EXT_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_AWG_AE) {
    constexpr char param[] = " AWG_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH3_AE) {
    constexpr char param[] = " CH3_AE\r\n";
    return io->writeStr(param);
  } else if (trigger == ACQ_CH4_AE) {
    constexpr char param[] = " CH4_AE\r\n";
    return io->writeStr(param);
  }

  io->writeCommandSeparator();
  return false;
}

bool scpi_rp::getAcqTriggerStateQ(BaseIO *io, bool *state) {
  constexpr char cmd[] = "ACQ:TRig:STAT?\r\n";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  auto value = io->read();
  if (value.isValid) {
    if (strcmp(value.value, "TD") == 0) {
      *state = true;
    } else if (strcmp(value.value, "WAIT") == 0) {
      *state = false;
    } else {
      io->flushCommand(value.next_value);
      return false;
    }
    io->flushCommand(value.next_value);
    return true;
  }
  return false;
}

bool scpi_rp::getAcqTriggerStateChQ(BaseIO *io, EACQChannel channel,
                                    bool *state) {
  constexpr char cmd[] = "ACQ:TRig:STAT:CH";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }
  constexpr char cmd2[] = "?\r\n";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }
  auto value = io->read();
  if (value.isValid) {
    if (strcmp(value.value, "TD") == 0) {
      *state = true;
    } else if (strcmp(value.value, "WAIT") == 0) {
      *state = false;
    } else {
      io->flushCommand(value.next_value);
      return false;
    }
    io->flushCommand(value.next_value);
    return true;
  }
  return false;
}

bool scpi_rp::getAcqTriggerFillQ(BaseIO *io, bool *state) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *state = atoi(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "ACQ:TRig:FILL?\r\n";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}

bool scpi_rp::getAcqTriggerFillChQ(BaseIO *io, EACQChannel channel,
                                   bool *state) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *state = (bool)atoi(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "ACQ:TRig:FILL:CH";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }
  constexpr char cmd2[] = "?\r\n";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}

bool scpi_rp::setAcqTriggerDelay(BaseIO *io, int value) {
  constexpr char cmd[] = "ACQ:TRig:DLY ";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(value)) {
    io->writeCommandSeparator();
    return false;
  }
  return io->writeCommandSeparator();
}

bool scpi_rp::getAcqTriggerDelayQ(BaseIO *io, int *_value) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *_value = atoi(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "ACQ:TRig:DLY?\r\n";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}

bool scpi_rp::setAcqTriggerDelayCh(BaseIO *io, EACQChannel channel, int value) {
  constexpr char cmd[] = "ACQ:TRig:DLY:CH";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }
  constexpr char cmd2[] = " ";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(value)) {
    io->writeCommandSeparator();
    return false;
  }
  return io->writeCommandSeparator();
}

bool scpi_rp::getAcqTriggerDelayChQ(BaseIO *io, EACQChannel channel,
                                    int *_value) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *_value = atoi(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "ACQ:TRig:DLY:CH";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }
  constexpr char cmd2[] = "?\r\n";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}

bool scpi_rp::setAcqTriggerHysteresis(BaseIO *io, float value) {
  constexpr char cmd[] = "ACQ:TRig:HYST ";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(value, 2, 5)) {
    io->writeCommandSeparator();
    return false;
  }
  return io->writeCommandSeparator();
}

bool scpi_rp::getAcqTriggerHysteresisQ(BaseIO *io, float *_value) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *_value = atof(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "ACQ:TRig:HYST?\r\n";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}

bool scpi_rp::setAcqTriggerLevel(BaseIO *io, float value) {
  constexpr char cmd[] = "ACQ:TRig:LEV ";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(value, 2, 5)) {
    io->writeCommandSeparator();
    return false;
  }
  return io->writeCommandSeparator();
}

bool scpi_rp::getAcqTriggerLevelQ(BaseIO *io, float *_value) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *_value = atof(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "ACQ:TRig:LEV?\r\n";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}

bool scpi_rp::setAcqTriggerLevelCh(BaseIO *io, EACQChannel channel,
                                   float value) {
  constexpr char cmd[] = "ACQ:TRig:LEV:CH";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }
  constexpr char cmd2[] = " ";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(value, 2, 5)) {
    io->writeCommandSeparator();
    return false;
  }
  return io->writeCommandSeparator();
}

bool scpi_rp::getAcqTriggerLevelChQ(BaseIO *io, EACQChannel channel,
                                    float *_value) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *_value = atof(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "ACQ:TRig:LEV:CH";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }
  constexpr char cmd2[] = "?\r\n";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}

bool scpi_rp::setAcqExtTriggerLevel(BaseIO *io, float value) {
  constexpr char cmd[] = "TRig:EXT:LEV ";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(value, 2, 5)) {
    io->writeCommandSeparator();
    return false;
  }
  return io->writeCommandSeparator();
}

bool scpi_rp::getAcqExtTriggerLevelQ(BaseIO *io, float *_value) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *_value = atof(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "TRig:EXT:LEV?\r\n";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}

bool scpi_rp::setAcqExtTriggerDebouncer(BaseIO *io, double value) {
  constexpr char cmd[] = "ACQ:TRig:EXT:DEBouncer:US ";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(value, 10, 0)) {
    io->writeCommandSeparator();
    return false;
  }
  return io->writeCommandSeparator();
}

bool scpi_rp::getAcqExtTriggerDebouncerQ(BaseIO *io, double *_value) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *_value = atof(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "ACQ:TRig:EXT:DEBouncer:US?\r\n";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}

bool scpi_rp::acqTriggerInterruptQ(BaseIO *io, int timeout_ms,
                                   EACQIntTrigger *state) {
  constexpr char cmd[] = "ACQ:TRig:INT";

  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }

  if (!io->writeNumber(timeout_ms)) {
    io->writeCommandSeparator();
    return false;
  }

  constexpr char cmd2[] = ":STAT?\r\n";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }

  auto value = io->read();
  if (value.isValid) {
    if (strcmp(value.value, "OK") == 0) {
      *state = EACQIntTrigger::ACQ_TR_OK;
    } else if (strcmp(value.value, "TIMEOUT") == 0) {
      *state = EACQIntTrigger::ACQ_TR_TIMEOUT;
    } else if (strcmp(value.value, "ERROR") == 0) {
      *state = EACQIntTrigger::ACQ_TR_ERROR;
    } else {
      io->flushCommand(value.next_value);
      return false;
    }
    io->flushCommand(value.next_value);
    return true;
  }
  return false;
}

bool scpi_rp::acqTriggerInterruptChQ(BaseIO *io, EACQChannel channel,
                                     int timeout_ms, EACQIntTrigger *state) {
  constexpr char cmd[] = "ACQ:TRig:INT";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }

  if (!io->writeNumber(timeout_ms)) {
    io->writeCommandSeparator();
    return false;
  }

  constexpr char cmd2[] = ":STAT:CH";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }

  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }

  constexpr char cmd3[] = "?\r\n";
  if (!io->writeStr(cmd3)) {
    io->writeCommandSeparator();
    return false;
  }

  auto value = io->read();
  if (value.isValid) {
    if (strcmp(value.value, "OK") == 0) {
      *state = EACQIntTrigger::ACQ_TR_OK;
    } else if (strcmp(value.value, "TIMEOUT") == 0) {
      *state = EACQIntTrigger::ACQ_TR_TIMEOUT;
    } else if (strcmp(value.value, "ERROR") == 0) {
      *state = EACQIntTrigger::ACQ_TR_ERROR;
    } else {
      io->flushCommand(value.next_value);
      return false;
    }
    io->flushCommand(value.next_value);
    return true;
  }
  return false;
}

bool scpi_rp::acqFillInterruptQ(BaseIO *io, int timeout_ms,
                                EACQIntTrigger *state) {
  constexpr char cmd[] = "ACQ:TRig:INT";

  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }

  if (!io->writeNumber(timeout_ms)) {
    io->writeCommandSeparator();
    return false;
  }

  constexpr char cmd2[] = ":FILL?\r\n";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }

  auto value = io->read();
  if (value.isValid) {
    if (strcmp(value.value, "OK") == 0) {
      *state = EACQIntTrigger::ACQ_TR_OK;
    } else if (strcmp(value.value, "TIMEOUT") == 0) {
      *state = EACQIntTrigger::ACQ_TR_TIMEOUT;
    } else if (strcmp(value.value, "ERROR") == 0) {
      *state = EACQIntTrigger::ACQ_TR_ERROR;
    } else {
      io->flushCommand(value.next_value);
      return false;
    }
    io->flushCommand(value.next_value);
    return true;
  }
  return false;
}

bool scpi_rp::acqFillInterruptChQ(BaseIO *io, EACQChannel channel,
                                  int timeout_ms, EACQIntTrigger *state) {
  constexpr char cmd[] = "ACQ:TRig:INT";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }

  if (!io->writeNumber(timeout_ms)) {
    io->writeCommandSeparator();
    return false;
  }

  constexpr char cmd2[] = ":FILL:CH";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }

  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }

  constexpr char cmd3[] = "?\r\n";
  if (!io->writeStr(cmd3)) {
    io->writeCommandSeparator();
    return false;
  }

  auto value = io->read();
  if (value.isValid) {
    if (strcmp(value.value, "OK") == 0) {
      *state = EACQIntTrigger::ACQ_TR_OK;
    } else if (strcmp(value.value, "TIMEOUT") == 0) {
      *state = EACQIntTrigger::ACQ_TR_TIMEOUT;
    } else if (strcmp(value.value, "ERROR") == 0) {
      *state = EACQIntTrigger::ACQ_TR_ERROR;
    } else {
      io->flushCommand(value.next_value);
      return false;
    }
    io->flushCommand(value.next_value);
    return true;
  }
  return false;
}

bool scpi_rp::setAcqTimestamp(BaseIO *io, uint64_t timestamp) {
  constexpr char cmd[] = "ACQ:TS ";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumberU64(timestamp)) {
    io->writeCommandSeparator();
    return false;
  }
  return io->writeCommandSeparator();
}

bool scpi_rp::getAcqTimestampQ(BaseIO *io, EACQChannel channel,
                               uint64_t *_value) {
  auto readValue = [&]() {
    auto value = io->read();
    if (value.isValid) {
      *_value = io->atou64_dec(value.value);
      io->flushCommand(value.next_value);
      return true;
    }
    return false;
  };
  constexpr char cmd[] = "ACQ:TS:CH";
  if (!io->writeStr(cmd)) {
    io->writeCommandSeparator();
    return false;
  }
  if (!io->writeNumber(channel)) {
    io->writeCommandSeparator();
    return false;
  }
  constexpr char cmd2[] = "?\r\n";
  if (!io->writeStr(cmd2)) {
    io->writeCommandSeparator();
    return false;
  }
  return readValue();
}