# Lissajous Plugin (and DVD thing)

## Brainstorming

- Operaciones binarias para calcular el color de las figuras.
- Frecuencia de muestreo no debería afectar al color, pero la amplitud (y a lo mejor la frecuencia de la señal real sí)
- ¿¿¿¿Cómo se representan las frecuencias???? Caso difícil: Buffer de 32 muestras, periodo de la onda son 100 muestras.
- Centro de coordenadas de las curvas no fijo.
- Fade out de los colores en función del tiempo (puede salir fatal jajaja)
- Incorporar librería [melatonin blur](https://github.com/sudara/melatonin_blur) para sombras y brillos optimizados.
- Icono DVD que choca con la pantalla, surge en instantes aleatorios, tiene un tiempo de vida de varios rebotes y resetea el timer.
- Gif de gato happy happy happy ![GIF](https://www.google.com/url?sa=i&url=https%3A%2F%2Ftenor.com%2Fview%2Fhappy-happy-happy-happy-happy-happy-cat-jumping-happy-cat-gif-17498744034444290732&psig=AOvVaw1i9ggoDgHYCUKyGoDG9FB4&ust=1732391862397000&source=images&cd=vfe&opi=89978449&ved=0CBAQjRxqFwoTCKDnid7c8IkDFQAAAAAdAAAAABAi)


## Setup the project

From a folder of your choice, execute the following commands to clone the contents of the repository.

```bash
git clone --recurse-submodules https://github.com/Javiolonchelo/Lissajous_plugin.git .
```

Then you must customize your project. You can do this by manually changing the contents of the `CMakeLists.txt` file, specifically in this part:

```cmake
# Customize your plugin here
set(COMPANY_NAME "dBob")
set(PROJECT_NAME LISSAJOUS_PLUGIN)
set(PLUGIN_TARGET_NAME "Lissajous")
set(PLUGIN_FINAL_NAME "Lissajous DVD")
set(PLUGIN_MANUFACTURER_CODE dBob)
set(PLUGIN_CODE LsDv)
set(FORMATS AU VST3 Standalone)
```

### Build the project

Open a terminal in the root folder of the project and execute the following command:

```bash
cmake -B build
```

Then a `LISSAJOUS_PLUGIN.sln` should have appeared in the `build` folder.

## Debugging your plugin in Visual Studio

Once you open the solution in Visual Studio, in the Solution Explorer you'll see a folder named "MyPlugin", with several targets. To debug them properly, follow these steps depending on the selected target.

### Standalone

Right-click on "Lissjous_Standalone" and select "Set as StartUp Project". Now you're ready to debug it.

### VST3

1. Right-click on "MyPlugin_VST3" and select "Set as StartUp Project".
2. Then, right-click on "MyPlugin_Standalone" and select "Properties". Navigate to "Configuration Properties" -> "Debugging".
3. Set the "Command" field to the path of your VST3 host. You can use the JUCE Audio Plugin Host, which should be located at `./modules/JUCE/extras/AudioPluginHost/Builds/VisualStudio2022/x64/Release/App` (or a similar path). You can also use a DAW of preference. I've seen Reaper used a lot for this purpose. I'm going to use Ableton with a default template, I thinks that's the way to go.

Once you start debugging, the audio host will open, and you can load your plugin by following these steps:

1. In the menu, select Options -> Edit the List of Available Plug-Ins...
2. Click on the "Options" button and select "Scan for new or updated VST3 plug-ins".
3. I recommend pressing "Clear list", then removing the existing paths, and finally pressing the "+" button to add the path to your root project folder. Then, press Scan and close the window.
4. Now, you can find your plugin in the list and load it.
5. Save the graph. In the menu, press "Save as" and select the root folder.

The last step ensures that whenever you debug the VST3, it's ready to go.
