aLL:
	g++ -o test_install   -I/usr/local/include -I/usr/local/include/mysql/   -Wl, standalone_example.cpp -lmysqlcppconn;

clean:
	rm test_install
