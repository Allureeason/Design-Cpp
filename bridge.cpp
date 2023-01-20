/*
 * 桥接模式
 *
*/

#include <iostream>
#include <string>

using namespace std;

// 视频格式抽象类
class VideoFormat {
public:
    VideoFormat(const std::string& format)
        :m_format(format) {}
    virtual ~VideoFormat() {}
    const std::string& getFormat() { return m_format; }
private:
    std::string m_format;
};

// 具体视频格式类实现
class MP4Format : public VideoFormat {
public:
    MP4Format(const std::string& format)
        :VideoFormat(format) {}
};

class AVIFormat : public VideoFormat {
public:
    AVIFormat(const std::string& format)
        :VideoFormat(format) {}
};

// 播放器抽象类
class Player {
public:
    Player() { m_videoFormat = nullptr; }
    virtual ~Player() {}
    virtual void play() = 0;
    VideoFormat* getVideoFormat() { return m_videoFormat; }
    void setVideoFormat(VideoFormat* vf) { m_videoFormat = vf; }
private:
    VideoFormat* m_videoFormat;
};

// 具体播放器实现类
class WinPlayer : public Player {
public:
    virtual void play() {
        VideoFormat* vf = getVideoFormat();
        if(!vf){
            std::cout << "need set a video format,try again." << std::endl;
            return;
        }

        std::cout << "play video by format: " << vf->getFormat() << std::endl;
    }
};

int main(int argc, char** argv) {
    Player* player = new WinPlayer;

    VideoFormat* mp4 = new MP4Format("mp4");
    VideoFormat* avi = new AVIFormat("avi");

    // 未设置播放格式
    player->play();

    // 设置MP4播放格式
    player->setVideoFormat(mp4);
    player->play();

    // 设置AVI播放格式
    player->setVideoFormat(avi);
    player->play();
    return 0;
}
