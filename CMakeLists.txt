cmake_minimum_required(VERSION 3.7)

project(EditorApp)

add_subdirectory(MathLib)

add_library(Engine
    Engine/AnimationObject.h
    Engine/Camera.cpp
    Engine/Camera.h
    Engine/Camera2D.cpp
    Engine/Camera2D.h
    Engine/Camera3D.cpp
    Engine/Camera3D.h
    Engine/DLLMain.cpp
    Engine/Engine.cpp
    Engine/Engine.dsp
    Engine/Engine.h
    Engine/Keys.cpp
    Engine/Keys.h
    Engine/RenderArgs.cpp
    Engine/RenderArgs.h
    Engine/RenderObject.h
    Engine/SelectionArgs.cpp
    Engine/SelectionArgs.h
    Engine/SelectionHandler.cpp
    Engine/SelectionHandler.h
    Engine/SelectionObject.h
    )

target_include_directories(Engine
    PRIVATE MathLib
    )

set(SRC_APP
    Bone.cpp
    Bone.h
    CameraPropertieBox.cpp
    CameraPropertieBox.h
    CameraTool.cpp
    CameraTool.h
    Collection.h
    Document.cpp
    Document.h
    IFileLoader.h
    IMesh.h
    IMeshGroup.h
    IModel.h
    IModelLoader.h
    ISequence.h
    ISkeleton.h
    Joint.cpp
    Joint.h
    KeyFrame.cpp
    KeyFrame.h
    MainForm.cpp
    MainForm.h
    MainToolBox.cpp
    MainToolBox.h
    Material.cpp
    Material.h
    Mesh.cpp
    Mesh.h
    MeshGroup.cpp
    MeshGroup.h
    Model.cpp
    Model.h
    Motion.cpp
    Motion.h
    MS3DLoader.cpp
    MS3DLoader.h
    Point.cpp
    Point.h
    RenderWindow.cpp
    RenderWindow.h
    resource.h
    resource.rc
    SelectionPropertieBox.cpp
    SelectionPropertieBox.h
    SelectionTool.cpp
    SelectionTool.h
    Sequence.cpp
    Sequence.h
    SequenceJoint.cpp
    SequenceJoint.h
    Skeleton.cpp
    Skeleton.h
    Tool.h
    ToolArgs.cpp
    ToolArgs.h
    ToolFactory.cpp
    ToolFactory.h
    ToolManager.cpp
    ToolManager.h
    Triangle.cpp
    Triangle.h
    Vertex.cpp
    Vertex.h
    Workspace.cpp
    Workspace.h
    WorkspaceToolBox.cpp
    WorkspaceToolBox.h
    )

add_executable(EditorApp
    ${SRC_APP}
    )

target_include_directories(EditorApp
    PRIVATE MathLib
    )

target_compile_features(EditorApp
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_link_libraries(EditorApp
    Engine
    MathLib
    )