## here is PATH setting to build the shared object.
# export PKG_LIBS=`Rscript -e "Rcpp:::LdFlags()"`
# export PKG_CXXFLAGS=`Rscript -e "Rcpp:::CxxFlags()"`

SRC = simm.cpp stdm.cpp comm.cpp uul.cpp Ruul.cpp
OBJ = simm.o   stdm.o   comm.o   uul.o   Ruul.o
TAR = Ruul.so

all:
	R CMD SHLIB $(SRC) -o $(TAR)

clean:
	rm $(OBJ) $(TAR)

