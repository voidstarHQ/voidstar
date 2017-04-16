#pragma once

#include <memory>

#include <Arguments.hh>
#include <Scene.hh>
#include <Events.hh>

class Scene;

class Manager {
public:
    Manager(std::shared_ptr<Arguments> args)
        : fullscreen_(false), args_(args), fileIndex_(0), scene_(0) {}
    virtual ~Manager() {}

    virtual void loadScene(std::shared_ptr<Scene> scene);
    virtual void init() = 0;
    virtual void run() = 0;

    virtual std::shared_ptr<Events> getEvents(int id=0) = 0;
    virtual std::shared_ptr<Mouse> getMouse(int id=0) = 0;

    void loadFile(size_t index);
    void loadFile(const std::string& filename);
    void loadNextFile() { loadFile((fileIndex_ + 1) % args_->input.size()); }
    void loadPrevFile() { loadFile((fileIndex_ - 1) % args_->input.size()); }

    virtual void toggleFullscreen() = 0;

    std::shared_ptr<Arguments> args() { return args_; }
    std::shared_ptr<Scene> scene() { return scene_; }

public:
    static std::string  /// 991337 --> "991,337"
    size2str (size_t size) {
        std::string str = std::to_string(size);
        int pos = str.length() - 3;
        while (pos > 0) {
            str.insert(pos, ",");
            pos -= 3;
        }
        return str;
    }

protected:
    bool fullscreen_;
    std::shared_ptr<Arguments> args_;
    size_t fileIndex_;
    std::shared_ptr<Scene> scene_;
};

std::shared_ptr<Manager> createManager(const std::string& str, std::shared_ptr<Arguments> args);

using ManagerFactoryFunc = std::function<std::shared_ptr<Manager>(std::shared_ptr<Arguments>)>;
extern const std::map<const std::string, ManagerFactoryFunc> managers;
