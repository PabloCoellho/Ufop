executar-tests-functional:
	g++ -o bin/funcional_test.out src/model.cpp src/system.cpp src/flow.cpp test/funcional/main.cpp test/funcional/funcional_tests.cpp

executar-tests-unit:
	g++ -o bin/unit_test.out src/model.cpp src/system.cpp src/flow.cpp test/unit/main.cpp test/unit/unit_tests.cpp

clean:
	rm -f bin/*.o bin/*.out

run-functional:
	./bin/funcional_test.out

run-unit:
	./bin/unit_test.out