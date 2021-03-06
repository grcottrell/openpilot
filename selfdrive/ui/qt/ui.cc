#include <QApplication>

#include "window.hpp"

int main(int argc, char *argv[]) {
  QSurfaceFormat fmt;
#ifdef __APPLE__
  fmt.setVersion(3, 2);
  fmt.setProfile(QSurfaceFormat::OpenGLContextProfile::CoreProfile);
  fmt.setRenderableType(QSurfaceFormat::OpenGL);
#else
  fmt.setRenderableType(QSurfaceFormat::OpenGLES);
#endif
  QSurfaceFormat::setDefaultFormat(fmt);

  QApplication a(argc, argv);

  MainWindow w;
#ifdef QCOM2
  w.showFullScreen();
#else
  w.setFixedSize(vwp_w, vwp_h);
  w.show();
#endif

  return a.exec();
}
