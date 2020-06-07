import QtQuick 2.3
import QtTest 1.0

TestCase {
    name: "MessageTest"

    function test_message() {
        compare(message, "Do it!")
    }
}
