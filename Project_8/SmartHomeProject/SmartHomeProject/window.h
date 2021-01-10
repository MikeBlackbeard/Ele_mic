#pragma once

enum Status{
  open, semiopen,close
};
class Window
{
private:
  Status status;
   public:
     Window (/ * args * /);
     ~Window ();
     void changestatus(status newStatus);
     void open;
     void close;
     void semiopen;
     status returnStatus();
   };
