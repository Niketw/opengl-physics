# OpenGL Physics Project

This is a C project using OpenGL for graphics, with the following libraries:
- **GLFW** for window and input management.
- **GLEW** for loading OpenGL extensions.
- **cglm** for mathematics.

The project is configured to be built on Windows using Visual Studio 2022 and vcpkg for dependency management.

## Prerequisites

Before you begin, ensure you have the following installed:

1.  **Visual Studio Code**: The editor used for this project. You can download it from the [official website](https://code.visualstudio.com/).
2.  **Visual Studio 2022**: Make sure the **Desktop development with C** workload is installed. This provides the required MSVC compiler and Windows SDK. You can get the Community version for free from the [Visual Studio website](https://visualstudio.microsoft.com/downloads/).
3.  **CMake**: Download and install the latest version from the [CMake website](https://cmake.org/download/). Make sure to select the option to add CMake to the system `PATH` for all users.
4.  **Git**: Required for cloning vcpkg and this repository. You can get it from the [Git website](https://git-scm.com/downloads).

## 1. Vcpkg Setup

This project uses [vcpkg](https://vcpkg.io/) to manage dependencies. You only need to do this setup once.

### Install vcpkg

1.  Choose a directory to install vcpkg. A good location is `C:\Dev\vcpkg` or `C:\vcpkg`.
2.  Open a PowerShell terminal and run the following commands:

    ```powershell
    # Clone the vcpkg repository
    git clone https://github.com/Microsoft/vcpkg.git C:\Dev\vcpkg

    # Run the bootstrap script to build vcpkg
    cd C:\Dev\vcpkg
    .\bootstrap-vcpkg.bat
    ```

### Set Environment Variables

For CMake to automatically find and use vcpkg, you must set the `VCPKG_ROOT` environment variable.

1.  Press the **Windows Key**, type `env`, and select **Edit the system environment variables**.
2.  In the System Properties window, click the **Environment Variables...** button.
3.  Under the **System variables** section, click **New...**.
4.  Enter the following:
    *   **Variable name**: `VCPKG_ROOT`
    *   **Variable value**: `C:\Dev\vcpkg` (or wherever you cloned vcpkg)
5.  Click **OK** on all windows to save the changes.
6.  **Important**: You must restart any open terminals or VS Code instances for this change to take effect.

## 2. Building and Running the Project

1.  Clone this repository to your local machine.
2.  Open the project folder in Visual Studio Code.
3.  If prompted, install the recommended C/C++ and CMake Tools extensions.

### First-Time Configuration

The first time you open the project, CMake needs to configure it. This will also trigger vcpkg to download and install the required libraries (`glfw3`, `glew`, `cglm`). This may take some time.

1.  Open the Command Palette (`Ctrl+Shift+P`).
2.  Type and select **CMake: Configure**.
3.  When prompted to select a preset, choose **windows-msvc-x64**.

You can monitor the progress in the **Output** panel in VS Code.

### Building the Code

-   Press **`Ctrl+Shift+B`** to run the default build task.

### Running the Application

-   Press **`F5`** to build (if needed) and run the application with the debugger attached.

## Recommended VS Code Extensions

To get the best experience when working with this project, it is highly recommended to install the following VS Code extensions:

-   [**C/C++ Extension Pack**](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack): This pack includes essential tools for C development in VS Code:
    -   **C/C++**: Provides IntelliSense, debugging, and code browsing.
    -   **CMake Tools**: Offers comprehensive support for configuring, building, and debugging CMake-based projects.
