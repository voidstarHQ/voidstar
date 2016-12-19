#pragma once

#include <Arguments.hh>
#include <Scene.hh>
#include <Events.hh>

class Manager {
public:
    Manager(Arguments* args)
        : fullscreen_(false), args_(args), fileIndex_(0), scene_(0) {}
    virtual ~Manager() {}

    virtual void loadScene(Scene* scene);
    virtual void init() = 0;
    virtual void run() = 0;

    virtual Events* getEvents(int id=0) = 0;
    virtual Mouse* getMouse(int id=0) = 0;

    void loadFile(size_t index);
    void loadFile(const std::string& filename);
    void loadNextFile() { loadFile((fileIndex_ + 1) % args_->input.size()); }
    void loadPrevFile() { loadFile((fileIndex_ - 1) % args_->input.size()); }

    virtual void toggleFullscreen() = 0;

    Arguments* args() { return args_; }
    Scene* scene() { return scene_; }

protected:
    bool fullscreen_;
    Arguments* args_;
    size_t fileIndex_;
    Scene* scene_;
};

Manager * createManager(const std::string str, Arguments *args);

using ManagerFactoryFunc = std::function<Manager*(Arguments*)>;
extern const std::map<const std::string, ManagerFactoryFunc> managers;
