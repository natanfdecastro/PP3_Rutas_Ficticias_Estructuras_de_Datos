BANDERAS = -g -lm --std=c11
SALIDA = rutas

all:
	gcc $(BANDERAS) *.c -o $(SALIDA)
	
run:
	./$(SALIDA)
	
.PHONY clean:
	rm *.o $(SALIDA)
