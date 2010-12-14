
Import('env')

env.Prepend(LIBS = [env['QWinMigratelib'], "user32"])
env.Append(CPPDEFINES = "AGAIN_EXPORTS")
env.Append(CPPDEFINES = "QT_QTWINMIGRATE_IMPORT")
env.Append(CPPPATH = env["vst"] + r"\public.sdk\source\vst2.x")

libmain = env.SharedLibrary('QtAgain', Glob("*.cpp") + ["vstplug.def", env["vst"] + r"\public.sdk\source\vst2.x\audioeffect.cpp", env["vst"] + r"\public.sdk\source\vst2.x\audioeffectx.cpp", ])
libmain = env.Install('$LIBDIR', libmain)
#env.Installer("qtagain")
