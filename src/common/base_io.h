#ifndef BASE_IO_H
#define BASE_IO_H

#include <stdint.h>

#include "structs.h"

namespace scpi_rp {

class BaseIO {
 public:
  BaseIO();

  virtual ~BaseIO();

  const Value readStr();
  const Value read();

  bool writeStr(const char *_data);

  bool writeCommandSeparator();

  void flush();
  void flushCommand(scpi_size value);

  bool readOnOff(bool *state);
  bool writeOnOff(bool state);

  virtual scpi_size write(const uint8_t *_data, scpi_size _size) = 0;

  scpi_size write(const char *_data, scpi_size _size);

 protected:
  int checkParamSeparator();
  int checkCommandSeparator();
  int fillBuffer();

  virtual scpi_size readToBuffer() = 0;

  uint8_t m_buffer[BASE_IO_BUFFER_SIZE];
  scpi_size m_bufferSize = 0;
  scpi_size m_bufferReadPos = 0;
};

}  // namespace scpi_rp

#endif
