#ifndef KCONFIG_H_
#define KCONFIG_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <direct.h>
    
    #define BRACET_NUMBER 2
    #define SECTION_SIZE 256

    #pragma pack (push, 1)
    typedef struct KConfig
    {
        char fileName[256];
        char sectionList[SECTION_SIZE][SECTION_SIZE];
        char keys[SECTION_SIZE][SECTION_SIZE];
        uint32_t counterList;
        uint32_t keysCounter;

        void (*setConfigFileName)(const char *configFileName);
        void (*addSection)(const char *sectionName);
        void (*set)(const char* sectionName, const char *key, const char *value);
        void (*showConfig)();
        void (*writeConfig)(const char *config, const char *fileMode);
        char* (*get)(const char *sectionName, const char *key);

    } KConfig;
    #pragma pack (pop)

    static KConfig *this;

    void initializeKConfig(KConfig *configObject);
    bool checkSectionList(const char* sectionName);
    bool checkSectionInFile(const char* sectionName);
    void searchSectionInFile(const char* sectionName, int *position, int *fileCursorPos);
    void writeSetForSection(const char* key, const char *value, const char *sectionName, uint32_t pos, int fileCursorPos);
    bool checkSet(const char* key, const char *value, const char* sectionName);
    char* substr(const char *src, int m, int n);
    
    static void setFileName(const char *configFileName);
    static void addSection(const char *sectionName);
    static void set(const char* sectionName, const char *key, const char *value);
    static char *get(const char *sectionName, const char *key);
    static void readFile();
    static void writeFile(const char *config, const char *fileMode);

#endif 