import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 1280
    height: 800
    color: "black"
    title: "HMI"
    visible: true
    Image {
        id: b_g
        source: "images/b_g.png"
        x: 0
        y: 0
        opacity: 1
    }
    Image {
        id: bg_p
        source: "images/bg_p.png"
        x: if(gear==0){450} else if(gear==1){518} else if(gear==2){585} else if(gear==3){653} else if(gear==4){719} else if (gear==5){780}
        y: 595
        opacity: 1
        Behavior on x {
            NumberAnimation {duration:300}
        }
    }
    Image {
        id: dashboard
        source: "images/dashboard.png"
        x: 8
        y: 101
        opacity: 1
    }
    Rectangle {
        id: pressure_font_left_panel
        x: 70
        y: 642
        width: 46
        height: 42
        color: "#006838"
        Text {
            id: pressure_font_left_value
            text: tire_pressure_1
            font.pointSize: 26
            anchors.centerIn: pressure_font_left_panel
            color: "white"
        }
    }
    Rectangle {
        id: pressure_font_right_panel
        x: 255
        y: 642
        width: 46
        height: 42
        color: "#006838"
        Text {
            id: pressure_font_right_value
            text: tire_pressure_2
            font.pointSize: 26
            anchors.centerIn: pressure_font_right_panel
            color: "white"
        }
    }
    Rectangle {
        id: pressure_back_left_panel
        x: 914
        y: 642
        width: 46
        height: 42
        color: "#006838"
        Text {
            id: pressure_back_left_value
            text: tire_pressure_3
            font.pointSize: 26
            anchors.centerIn: pressure_back_left_panel
            color: "white"
        }
    }
    Rectangle {
        id: pressure_back_right_panel
        x: 1101
        y: 642
        width: 46
        height: 42
        color: "#006838"
        Text {
            id: pressure_back_right_value
            text: tire_pressure_4
            font.pointSize: 26
            anchors.centerIn: pressure_back_right_panel
            color: "white"
        }
    }
    Image {
        id: tire_pressure_font_left_warning
        source: "images/tire_pressure_warning.png"
        x: 28
        y: 646
        opacity: if(tire_pressure_1 < 20) {1} else {0}
        Behavior on opacity {
            NumberAnimation { duration:100}
        }
    }
    Image {
        id: tire_pressure_font_right_warning
        source: "images/tire_pressure_warning.png"
        x: 369
        y: 645
        opacity: if(tire_pressure_2 < 20) {1} else {0}
        Behavior on opacity {
            NumberAnimation { duration:100}
        }
    }
    Image {
        id: tire_pressure_back_left_warning
        source: "images/tire_pressure_warning.png"
        x: 872
        y: 646
        opacity: if(tire_pressure_3 < 20) {1} else {0}
        Behavior on opacity {
            NumberAnimation { duration:100}
        }
    }
    Image {
        id: tire_pressure_back_right_warning
        source: "images/tire_pressure_warning.png"
        x: 1214
        y: 645
        opacity: if(tire_pressure_4 < 20) {1} else {0}
        Behavior on opacity {
            NumberAnimation { duration:100}
        }
    }
    Rectangle {
        id: speed_panel
        x: 597
        y: 299
        width: 92
        height: 41
        color: "#282D42"
        Text {
            id: value_speed
            text: speed
            font.pointSize: 26
            anchors.centerIn: speed_panel
            color: "white"

        }
    }
    Rectangle {
        id: efficiency_panel
        x: 515
        y: 367
        width: 92
        height: 41
        color: "#282D42"
        Text {
            id: efficiency_value
            text: efficiency
            font.pointSize: 26
            anchors.centerIn: efficiency_panel
            color: "white"
        }
    }
    Rectangle {
        id: odometer_panel
        x: 677
        y: 367
        width: 92
        height: 41
        color: "#282D42"
        Text {
            id: odometer_value
            text: odometer
            font.pointSize: 26
            anchors.centerIn: odometer_panel
            color: "white"
        }
    }
    Rectangle {
        id: env_temp_panel
        x: 577
        y: 466
        width: 140
        height: 50
        color: "#282D42"
        Text {
            id: env_temp_value
            text: env_temp+"°C"
            font.pointSize: 26
            anchors.centerIn: env_temp_panel
            color: "white"
        }
    }
    Image {
        id: needle_speed
        source: "images/needle_kph.png"
        x: 377
        y: 134
        opacity: 1

       transform: Rotation {
           origin.x: 263 //640-377
           origin.y: 266 //400-134
           angle: if (speed >=0 && speed <=240 ) {speed + 0.5} else {240}
           Behavior on angle {
               NumberAnimation {duration:100}
           }
       }
       smooth: true
    }
    Image {
        id: needel_rpm
        source: "images/needel_rpm.png"
        x: 88
        y: 165
        opacity: 1

        transform: Rotation {
            origin.x: 176 //264-88
            origin.y: 176 //341-165
            angle: if (rpms<= 9000) {(rpms/1000) * 20} else {180}
            Behavior on angle {
                NumberAnimation {duration:100}
            }
        }
        smooth: true
    }
    Image {
        id: needle_fuel
        source: "images/needle_fuel.png"
        x: 914
        y: 229
        opacity: 1

        transform: Rotation {
            origin.x: 136 //1050-914
            origin.y: 136 //365-229
            angle: if(fuel<=60) {-fuel*73/60} else {-73}
            Behavior on angle {
                NumberAnimation {duration:100}
            }
        }
        smooth: true
    }
    Image {
        id: needle_temp
        source: "images/needle_temp.png"
        x: 912
        y: 179
        opacity: 1

        transform: Rotation {
            origin.x: 138 //1050-912
            origin.y: 136 //315-179
            angle: if(temp>=0 && temp<=150) {-temp * 73/150} else {-73}
            Behavior on angle {
                NumberAnimation {duration:100}
            }
        }
        smooth: true
    }
    Image {
        id: temperature_static
        source: "images/temperature_static.png"
        x: 1085
        y: 216
        opacity: if(temp<100) {1} else {0}
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: temperature_warning
        source: "images/temperature_warning.png"
        x: 1085
        y: 216
        opacity: if(temp>=100) {1} else {0}
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: fuel_static
        source: "images/fuel_static.png"
        x: 1084
        y: 410
        opacity: if(fuel > 20) {1} else {0}
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: fuel_warning
        source: "images/fuel_warning.png"
        x: 1084
        y: 410
        opacity: if(fuel <= 20) {1} else {0}
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: left_narrow_signal
        source: "images/left_narrow.png"
        x: 397
        y: 165
        opacity: left_narrow
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: low_beam_signal
        source: "images/low_beam.png"
        x: 357
        y: 212
        opacity: low_beam
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: hand_brake_signal
        source: "images/hand_brake.png"
        x: 328
        y: 258
        opacity: hand_brake
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: check_engine_signal
        source: "images/check_engine.png"
        x: 309
        y: 306
        opacity: check_engine
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: airbag_signal
        source: "images/airbag.png"
        x: 302
        y: 355
        opacity: airbag
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: key_status_signal
        source: "images/key_status.png"
        x: 297
        y: 412
        opacity: key_status
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: parking_brake_signal
        source: "images/parking__brake.png"
        x: 309
        y: 467
        opacity: parking_brake
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: battery_warning_signal
        source: "images/battery_warning.png"
        x: 332
        y: 517
        opacity: low_battery
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: right_narrow_signal
        source: "images/right_narrow.png"
        x: 857
        y: 166
        opacity: right_narrow
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: high_beam_signal
        source: "images/high_beam.png"
        x: 892
        y: 213
        opacity: high_beam
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: oil_signal
        source: "images/oil.png"
        x: 914
        y: 258
        opacity: oil
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: seat_belt_signal
        source: "images/seat_belt.png"
        x: 935
        y: 298
        opacity: seat_belt
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: abs_brake_signal
        source: "images/abs_brake.png"
        x: 945
        y: 361
        opacity: abs_brake
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: door_warning_signal
        source: "images/door_warning.png"
        x: 954
        y: 411
        opacity: door_warning
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: exterior_light_fault_signal
        source: "images/exterior_light_fault.png"
        x: 935
        y: 467
        opacity: exterior_light_fault
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Image {
        id: hazard_lights_signal
        source: "images/hazard_lights.png"
        x: 912
        y: 512
        opacity: hazard_lights
        Behavior on opacity {
            NumberAnimation {duration:100}
        }
    }
    Rectangle {
        id: black_panel
        width:1280
        height:800
        color:"black"
        z:8
        opacity: shutdown
        Behavior on opacity {
            NumberAnimation { duration:100}
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}D{i:52;invisible:true}
}
##^##*/
