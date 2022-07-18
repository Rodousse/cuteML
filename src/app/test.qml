import QtMultimedia 1.15
import QtQuick.Controls 2.15
import QtQuick.Controls 2.15 as Multimedia
import "path/to/directory"
import "path/to/directory" as MyModule

Rectangle {
    id: photo                                               // id on the first line makes it easy to find an object

    property bool thumbnail: false                          // property declarations
    property alias image: photoImage.source

    signal clicked                                          // signal declarations

    function doSomething(x)                                 // javascript functions
    {
        return x + photoImage.width
    }
    Page {
    Button {
        text: qsTr("Restore default settings")
        onClicked: backend.restoreDefaults()
    }
}

    color: "gray"                                           // object properties
    x: 20                                                   // try to group related properties together
    y: 20
    height: 150
    width: {                                                // large bindings
        if (photoImage.width > 200) {
            photoImage.width;
        } else {
            200;
        }
    }

    Rectangle {                                             // child objects
        id: border
        anchors.centerIn: parent; color: "white"

        Image {
            id: photoImage
            anchors.centerIn: parent
        }
    }

    states: State {                                         // states
        name: "selected"
        PropertyChanges { target: border; color: "red" }
    }

    transitions: Transition {                               // transitions
        from: ""
        to: "selected"
        ColorAnimation { target: border; duration: 200 }
    }
}
