Built-in make varalbe

myprog: main.o one.o
	$(cc) -o $@ $^ $(LDFLAGS)

- $@ target of each rule (myprog)
- $^ dependencies of the rule (the .o list after :)
- $< the first denpendency (main.o in this case)
-
