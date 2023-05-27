compile-tests-functional:
	g++ -o bin/funcional_test.out src/lib/model.cpp src/lib/system.cpp src/lib/flow.cpp test/funcional/main.cpp test/funcional/funcional_tests.cpp

compile-tests-unit:
	g++ -o bin/unit_test.out src/lib/model.cpp src/lib/system.cpp src/lib/flow.cpp test/unit/main.cpp test/unit/mem_usage.cpp test/unit/unit_flow.cpp test/unit/unit_model.cpp test/unit/unit_system.cpp

clean:
	rm -f bin/*.o bin/*.out

run-functional:
	./bin/funcional_test.out

run-unit:
	./bin/unit_test.out



