import QtQuick 2.3
import QtTest 1.0
import elevons.team 1.0

Item {
    Repeater {
        model: modelProvider.messageList
        delegate: TestCase {
            name: "Model"
            when: TestModelProvider.isCompleted
            function test_roles() {
                switch (index) {
                case 0:
                    compare(model.name, "Ivan");
                    compare(model.id,   "3621897462");
                    compare(model.text, "Andryukha, we have a corpse.");
                    break
                case 1:
                    compare(model.name, "Nikolay");
                    compare(model.id,   "2897430847");
                    compare(model.text, "Possibly a crime!");
                    break
                case 2:
                    compare(model.name, "Michail");
                    compare(model.id,   "5465484984");
                    compare(model.text, "On the horses!");
                    testClear.when = true
                    break
                }
            }
        }
    }

    TestCase {
        id: testClear
        when: false

        function test_clear() {
            TestModelProvider.clear()
            compare(modelProvider.messageList.count, 0)
        }
    }
}
