# Make sure that git is installed
if ! command -v git &> /dev/null
then
    echo "git could not be found"
    exit
fi

# Download the raylib source code
# If the source code is already downloaded, then update it

if [ -d "raylib" ]; then
    cd raylib
    git pull
    cd ..
else
    git clone --depth=1 https://github.com/raysan5/raylib.git

    # Check if the download was successful
    if [ $? -ne 0 ]; then
        echo "Failed to download raylib"
        exit
    fi
fi

# Download the raygui source code

if [ -d "raygui" ]; then
    cd raygui
    git pull
    cd ..
else
    git clone --depth=1 https://github.com/raysan5/raygui.git

    # Check if the download was successful
    if [ $? -ne 0 ]; then
        echo "Failed to download raygui"
        exit
    fi
fi
