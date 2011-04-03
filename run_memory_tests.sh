valgrind --leak-check=full --show-reachable=yes --log-file=smart_class_report1.txt ./build/main Tests/sample1.txt
valgrind --leak-check=full --show-reachable=yes --log-file=smart_class_report2.txt ./build/main Tests/sample2.txt
valgrind --leak-check=full --show-reachable=yes --log-file=smart_class_report3.txt ./build/main Tests/sample3.txt
