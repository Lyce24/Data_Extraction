#include "bitio.hh"
#include <iostream>

using namespace std;

BitInput::BitInput(std::istream& is)
  :in(is), buf(0), nbits(8)
{}

bool BitInput::input_bit()
{
    if (nbits == 8)
    {
      buf = in.get();
      nbits = 0;
    }
    bool val;
    val = buf >> (7 - nbits) & 1;
    nbits++;
    return val;
}



BitOutput::BitOutput(std::ostream& os)
  :out(os), buf(0), nbits(0)
{}

void BitOutput::output_bit(bool bit)
{
    if (BitOutput::nbits == 8)
    {
      out.put(buf);
      buf = 0;      
      nbits = 0;
    }
    buf = buf << 1;
    buf = buf | bit;
    nbits++;
    return ;
}

BitOutput::~BitOutput()
{
  if (nbits != 8)
  {
    while (nbits != 8)
    {
      buf = buf << 1;
      nbits++;
    }
  }
  out.put(buf);
}


