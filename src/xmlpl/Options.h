#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <vector>

#include <xmlpl/cpp/runtime/Version.h>

namespace xmlpl {
  class Language;

  class Options {
    static Options *instance;

    bool useLineInfo;
    std::vector<std::string> libraryPath;
    Language *language;
    unsigned int verbosity;
    bool buildLibrary;
    bool saveTemps;
    bool debugMode;
    bool dumpCore;

    Version version;

    Options();

  public:
    static Options *getInstance()
    {if (!instance) instance = new Options; return instance;}

    bool getUseLineInfo() const {return useLineInfo;}
    void setUseLineInfo(const bool useLineInfo)
    {this->useLineInfo = useLineInfo;}

    const std::vector<std::string> &getLibraryPath() const
    {return libraryPath;}
    void setLibraryPath(const std::string path);
    void addToLibraryPath(const std::string path);

    Language *getLanguage() {return language;}
    void setLanguage(Language *language) {this->language = language;}

    const unsigned int getVerbosity() const {return verbosity;}
    void increaseVerbosity() {verbosity++;}

    bool getBuildLibrary() const {return buildLibrary;}
    void setBuildLibrary(const bool buildLibrary)
    {this->buildLibrary = buildLibrary;}

    bool getSaveTemps() const {return saveTemps;}
    void setSaveTemps(const bool saveTemps) {this->saveTemps = saveTemps;}

    bool getDebugMode() const {return debugMode;}
    void setDebugMode(const bool debugMode) {this->debugMode = debugMode;}

    bool getDumpCore() const {return dumpCore;}
    void setDumpCore(const bool dumpCore) {this->dumpCore = dumpCore;}

    void setVersion(const Version &version) {this->version = version;}
    const Version &getVersion() const {return version;}
  };
};
#endif // OPTIONS_H
