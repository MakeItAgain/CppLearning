# 定义编译器
CXX = g++
# 定义编译选项
CXXFLAGS = -I.

# 定义目标文件
OBJS = main.o intermediate/intermediate.o  algorithms/dp.o

# 定义可执行文件名
TARGET = program

# 默认目标
all: $(TARGET)

# 链接可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# 编译源文件
main.o: main.cpp intermediate/intermediate.h
	$(CXX) $(CXXFLAGS) -c main.cpp

intermediate/intermediate.o: intermediate/intermediate.cpp intermediate/intermediate.h
	$(CXX) $(CXXFLAGS) -c intermediate/intermediate.cpp -o intermediate/intermediate.o
	
algorithms/dp.o:  algorithms/dp.cpp algorithms/dp.h
	$(CXX) $(CXXFLAGS) -c algorithms/dp.cpp -o algorithms/dp.o
# 清理生成的文件
clean:
	rm -f $(OBJS) 
