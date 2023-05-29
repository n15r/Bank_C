add_subdirectory(components)
add_subdirectory(views)
aux_source_directory(. DIR_UI_SRC)
add_library(AppUi ${DIR_UI_SRC})
