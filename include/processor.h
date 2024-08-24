#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // See src/processor.cpp

  // Declare any necessary private members
private:
  // Store the previous values of CPU times to calculate the utilization
  long prev_idle_ = 0;
  long prev_non_idle_ = 0;
  long prev_total_ = 0;
};

#endif