/*
 * A class to store valid dates
 */

#pragma once // Don't include me more than once

class Date {
  public:
    Date(unsigned y, unsigned m, unsigned d);

    Date()
      : Date(2018, 10, 26)
    {
    }

    unsigned year() const { return y_; }
    unsigned month() const { return m_; }
    unsigned day() const { return d_; }

  private:
    unsigned y_;
    unsigned m_;
    unsigned d_;

    bool is_valid() const;
};

