
all: build

clean:
	rm -r ./**/build

build:
	xcodebuild -project App/BitBar.xcodeproj
	ps aux | grep $(PROJECT_NAME) | grep -v grep >/dev/null 2>&1 && killall $(PROJECT_NAME)
	open $(PROJECT)/../build/Release/$(PROJECT_NAME).app

