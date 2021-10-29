#pragma once

#include <memory>

#include "voidstar/arguments.h"
#include "voidstar/indices.h"
#include "voidstar/managers/events.h"
#include "voidstar/registrar.h"
#include "voidstar/scenes/scene.h"
#include "voidstar/size2str.h"

class Manager {
 public:
  Manager(std::shared_ptr<Arguments>& args)
      : args_(args), sliding_window_length_(args_->sliding_window_length) {}
  virtual ~Manager() {}

  virtual void loadScene(std::shared_ptr<Scene> scene);
  virtual void init() = 0;
  virtual void run() = 0;

  virtual std::shared_ptr<Events> getEvents() = 0;

  bool FileJustChanged() {
    bool x = file_just_changed_;
    if (file_just_changed_) file_just_changed_ = false;
    return x;
  }
  bool loadFile(size_t index);
  void loadFile(const std::string& filename);
  void loadNextFile() {
    loadFile((fileIndex_ + 1) % args_->paths.size());
    slide_window_leftmost();
  }
  void loadPrevFile() {
    loadFile((fileIndex_ - 1) % args_->paths.size());
    slide_window_leftmost();
  }

  virtual void ToggleFullscreen() = 0;

  std::shared_ptr<Arguments> args() const { return args_; }
  std::shared_ptr<Scene> scene() const { return scene_; }

  void slide_window_leftmost() { sliding_window_offset_ = 0; }

  void slide_window_left() {
    const auto step = args_->sliding_step;
    sliding_window_offset_ =
        (sliding_window_offset_ > step)
            ? sliding_window_offset_ - args_->sliding_step_factor * step
            : 0;
  }
  void slide_window_right() {
    sliding_window_offset_ += args_->sliding_step_factor * args_->sliding_step;
  }
  void slide_window_up() { sliding_window_length_ += args_->sliding_step; }
  void slide_window_down() {
    const auto step = args_->sliding_step;
    sliding_window_length_ = (sliding_window_length_ > step)
                                 ? sliding_window_length_ - step
                                 : args_->sliding_window_length;
  }

  bool slide_window(VertIndices& selected, const VertIndices& indices) {
    using offset_t = VertIndices::const_iterator::difference_type;
    const offset_t woffset = static_cast<offset_t>(sliding_window_offset_);
    const offset_t wlength = static_cast<offset_t>(sliding_window_length_);
    auto left = indices.begin() + woffset;
    if (left > indices.end()) left = indices.end() - woffset;
    if (left < indices.begin()) left = indices.begin();
    auto right = std::min(indices.end(), left + wlength);
    if (sliding_window_left_ != &left[0] ||
        sliding_window_right_ != &right[0]) {
      selected.assign(left, right);
      sliding_window_left_ = &left[0];
      sliding_window_right_ = &right[0];
      std::cout << "#selected: " << size2str(selected.size()) << std::endl;
      return true;
    }
    return false;
  }

 protected:
  bool fullscreen_ = false;
  // TODO: move attributes (and their methods) marked 'this'
  // to scene_ object so sliding window, loader & things can
  // be set per scene_.
  bool file_just_changed_ = false;  // this
  std::shared_ptr<Arguments> args_;
  size_t fileIndex_ = 0;
  std::shared_ptr<Scene> scene_ = nullptr;       // TODO: make this a collection
  size_t sliding_window_offset_ = 0;             // this
  size_t sliding_window_length_;                 // this
  const Index* sliding_window_left_ = nullptr;   // this
  const Index* sliding_window_right_ = nullptr;  // this
};

REGISTRY_DECLARATION_FOR(Manager,
                         std::shared_ptr<Manager>(std::shared_ptr<Arguments>));
#define REGISTER_MANAGER(KLASS) \
  REGISTRY_REGISTER_FOR(        \
      Manager, #KLASS, KLASS,   \
      (std::shared_ptr<Arguments> args) { return KLASS::instance(args); })
