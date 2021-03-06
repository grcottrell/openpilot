#include <QUrl>
#include "qt/qt_sound.hpp"

QtSound::QtSound() {
  for (auto &kv : sound_map) {
    auto path = QUrl::fromLocalFile(kv.second.first);
    sounds[kv.first].setSource(path);
  }
}

bool QtSound::play(AudibleAlert alert) {
  sounds[alert].setLoopCount(sound_map[alert].second);
  sounds[alert].play();
  return true;
}

void QtSound::stop() {
  for (auto &kv : sounds) {
    kv.second.stop();
  }
}

void QtSound::setVolume(int volume) {
  // TODO: implement this
}

QtSound::~QtSound() {

}
