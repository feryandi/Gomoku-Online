import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 240
    height: 160
    title: "Login"

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
        id: labelUsername
        x: 15
        y: 27
        text: qsTr("Username")
        font.pointSize: 11
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Label {
        id: labelServerIP
        x: 15
        y: 60
        text: qsTr("Server IP")
        font.pointSize: 11
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Label {
        id: labelServerPort
        x: 15
        y: 96
        text: qsTr("Server Port")
        font.pointSize: 11
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    TextField {
        id: textUsername
        x: 98
        y: 27
        placeholderText: qsTr("user_name")
    }

    TextField {
        id: textServerIP
        x: 98
        y: 60
        placeholderText: qsTr("127.0.0.1")
    }

    TextField {
        id: textServerPort
        x: 98
        y: 96
        placeholderText: qsTr("55555")
    }

    Button {
        id: buttonPlay
        x: 15
        y: 128
        width: 210
        height: 23
        text: qsTr("Play!")
    }
}

