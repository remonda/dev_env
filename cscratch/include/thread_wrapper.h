#ifndef CLASS_THREAD_WRAPPER_H
#define CLASS_THREAD_WRAPPER_H

class ThreadWrapper {
public:
  ThreadWrapper() = default;
//   ThreadWrapper(const ThreadWrapper &t) = delete;
//   ThreadWrapper &operator=(const ThreadWrapper &t) = delete;
  ~ThreadWrapper() = default;

  void operator() ()const;

//   private:

};

#endif