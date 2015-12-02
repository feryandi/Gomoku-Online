import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 360
    height: 480
    title: "Lobby"

    /*menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }*/

    Label {
        id: labelCreateRoom
        x: 15
        y: 27
        text: qsTr("Create a new room")
        font.pointSize: 11
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Label {
        id: labelSelectRoom
        x: 15
        y: 101
        text: qsTr("Or select a channel from the list below")
        font.pointSize: 11
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    TextField {
        id: textCreateRoom
        x: 15
        y: 51
        width: 232
        height: 20
        placeholderText: qsTr("#YourRoom")
    }

    Button {
        id: buttonCreate
        x: 253
        y: 50
        width: 92
        height: 23
        text: qsTr("Create")
    }
}

