    // Functies voor audioapparaatbeheer
    void InitAudioDevice(void);                                     // Initialiseer het audioapparaat en de context
    void CloseAudioDevice(void);                                    // Sluit het audioapparaat en de context
    bool IsAudioDeviceReady(void);                                  // Controleer of het audioapparaat succesvol is geïnitialiseerd
    void SetMasterVolume(float volume);                             // Stel het hoofdvolume in (luisteraar)
    float GetMasterVolume(void);                                    // Lees het hoofdvolume uit (luisteraar)

    // Functies voor het laden/vrijgeven van waves en geluiden
    Wave LoadWave(const char *fileName);                            // Laad wavedata uit een bestand
    Wave LoadWaveFromMemory(const char *fileType, const unsigned char *fileData, int dataSize); // Laad wavedata uit een geheugenbuffer, fileType verwijst naar de extensie: bijv. '.wav'
    bool IsWaveValid(Wave wave);                                    // Controleer of de wavedata geldig is (geladen data en parameters)
    Sound LoadSound(const char *fileName);                          // Laad een geluid uit een bestand
    Sound LoadSoundFromWave(Wave wave);                             // Laad een geluid uit wavedata
    Sound LoadSoundAlias(Sound source);                             // Maak een nieuw geluid dat dezelfde sampledata deelt als het brongeluid, maar er niet de eigenaar van is
    bool IsSoundValid(Sound sound);                                 // Controleer of een geluid geldig is (data geladen en buffers geïnitialiseerd)
    void UpdateSound(Sound sound, const void *data, int sampleCount); // Werk de geluidsbuffer bij met nieuwe data (standaardformaat: 32-bit float, stereo)
    void UnloadWave(Wave wave);                                     // Geef wavedata vrij
    void UnloadSound(Sound sound);                                  // Geef een geluid vrij
    void UnloadSoundAlias(Sound alias);                             // Geef een geluidsalias vrij (geeft de sampledata niet vrij)
    bool ExportWave(Wave wave, const char *fileName);               // Exporteer wavedata naar een bestand, geeft true terug bij succes
    bool ExportWaveAsCode(Wave wave, const char *fileName);         // Exporteer de sampledata van een wave naar code (.h), geeft true terug bij succes

    // Functies voor wave- en geluidsbeheer
    void PlaySound(Sound sound);                                    // Speel een geluid af
    void StopSound(Sound sound);                                    // Stop het afspelen van een geluid
    void PauseSound(Sound sound);                                   // Pauzeer een geluid
    void ResumeSound(Sound sound);                                  // Hervat een gepauzeerd geluid
    bool IsSoundPlaying(Sound sound);                               // Controleer of een geluid momenteel wordt afgespeeld
    void SetSoundVolume(Sound sound, float volume);                 // Stel het volume van een geluid in (1.0 is het maximumniveau)
    void SetSoundPitch(Sound sound, float pitch);                   // Stel de toonhoogte van een geluid in (1.0 is het standaardniveau)
    void SetSoundPan(Sound sound, float pan);                       // Stel de stereobalans van een geluid in (-1.0 links, 0.0 midden, 1.0 rechts)
    Wave WaveCopy(Wave wave);                                       // Kopieer een wave naar een nieuwe wave
    void WaveCrop(Wave *wave, int initFrame, int finalFrame);       // Snijd een wave bij tot een opgegeven bereik van frames
    void WaveFormat(Wave *wave, int sampleRate, int sampleSize, int channels); // Zet wavedata om naar het gewenste formaat
    float *LoadWaveSamples(Wave wave);                              // Laad de samples van een wave als een array van 32-bit floats
    void UnloadWaveSamples(float *samples);                         // Geef de samples vrij die geladen zijn met LoadWaveSamples()

    // Functies voor muziekbeheer
    Music LoadMusicStream(const char *fileName);                    // Laad een muziekstream uit een bestand
    Music LoadMusicStreamFromMemory(const char *fileType, const unsigned char *data, int dataSize); // Laad een muziekstream uit data
    bool IsMusicValid(Music music);                                 // Controleer of een muziekstream geldig is (context en buffers geïnitialiseerd)
    void UnloadMusicStream(Music music);                            // Geef een muziekstream vrij
    void PlayMusicStream(Music music);                              // Begin met het afspelen van muziek
    bool IsMusicStreamPlaying(Music music);                         // Controleer of muziek wordt afgespeeld
    void UpdateMusicStream(Music music);                            // Werk de buffers voor het streamen van muziek bij
    void StopMusicStream(Music music);                              // Stop het afspelen van muziek
    void PauseMusicStream(Music music);                             // Pauzeer muziek
    void ResumeMusicStream(Music music);                            // Hervat gepauzeerde muziek
    void SeekMusicStream(Music music, float position);              // Spring naar een positie in de muziek (in seconden)
    void SetMusicVolume(Music music, float volume);                 // Stel het volume van muziek in (1.0 is het maximumniveau)
    void SetMusicPitch(Music music, float pitch);                   // Stel de toonhoogte van muziek in (1.0 is het standaardniveau)
    void SetMusicPan(Music music, float pan);                       // Stel de stereobalans van muziek in (-1.0 links, 0.0 midden, 1.0 rechts)
    float GetMusicTimeLength(Music music);                          // Lees de lengte van de muziek uit (in seconden)
    float GetMusicTimePlayed(Music music);                          // Lees uit hoeveel van de muziek al is afgespeeld (in seconden)

    // Functies voor audiostreambeheer
    AudioStream LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels); // Laad een audiostream (om ruwe pcm-audiodata te streamen)
    bool IsAudioStreamValid(AudioStream stream);                    // Controleer of een audiostream geldig is (buffers geïnitialiseerd)
    void UnloadAudioStream(AudioStream stream);                     // Geef een audiostream en het bijbehorende geheugen vrij
    void UpdateAudioStream(AudioStream stream, const void *data, int frameCount); // Werk de buffers van een audiostream bij met data
    bool IsAudioStreamProcessed(AudioStream stream);                // Controleer of een van de buffers van een audiostream opnieuw gevuld moet worden
    void PlayAudioStream(AudioStream stream);                       // Speel een audiostream af
    void PauseAudioStream(AudioStream stream);                      // Pauzeer een audiostream
    void ResumeAudioStream(AudioStream stream);                     // Hervat een gepauzeerde audiostream
    bool IsAudioStreamPlaying(AudioStream stream);                  // Controleer of een audiostream momenteel wordt afgespeeld
    void StopAudioStream(AudioStream stream);                       // Stop het afspelen van een audiostream
    void SetAudioStreamVolume(AudioStream stream, float volume);    // Stel het volume van een audiostream in (1.0 is het maximumniveau)
    void SetAudioStreamPitch(AudioStream stream, float pitch);      // Stel de toonhoogte van een audiostream in (1.0 is het standaardniveau)
    void SetAudioStreamPan(AudioStream stream, float pan);          // Stel de stereobalans van een audiostream in (-1.0 tot 1.0, 0.0 is het midden)
    void SetAudioStreamBufferSizeDefault(int size);                 // Standaardgrootte voor nieuwe audiostreams
    void SetAudioStreamCallback(AudioStream stream, AudioCallback callback); // Callback van de audiothread voor het aanvragen van nieuwe data

    void AttachAudioStreamProcessor(AudioStream stream, AudioCallback processor); // Koppel een audiostreamprocessor aan een stream, deze ontvangt frames x 2 samples als 'float' (stereo)
    void DetachAudioStreamProcessor(AudioStream stream, AudioCallback processor); // Ontkoppel een audiostreamprocessor van een stream

    void AttachAudioMixedProcessor(AudioCallback processor); // Koppel een audiostreamprocessor aan de hele audiopipeline, deze ontvangt frames x 2 samples als 'float' (stereo)
    void DetachAudioMixedProcessor(AudioCallback processor); // Ontkoppel een audiostreamprocessor van de hele audiopipeline