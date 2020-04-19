#pragma once

struct Events {
 public:
  virtual ~Events() {}
  virtual bool keyPressed(int key) = 0;
  virtual bool keyReleased(int key) = 0;
  virtual bool keyUp(int key) = 0;
  virtual bool keyDown(int key) = 0;
  virtual void update() = 0;
};
