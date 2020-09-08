import QtQuick 2.3
import QtTest 1.0

Item {
    Repeater {
        model: userListModel
        delegate: Item {
            TestCase {
                name: "Model"
                function test_roles() {
                    switch (index) {
                    case 0:
                        compare(model.id,   "3600000000");
                        compare(model.name, "Ivan");
                        break
                    case 1:
                        compare(model.id,   "3700000000");
                        compare(model.name, "Error");
                        break
                    }
                }
            }
        }
    }

    TestCase {
        id: testCount
        function test_count() {
            compare(userListModel.count, 2)
        }
    }
}

