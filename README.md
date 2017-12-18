`README.md` for version 0.1.0 of Ruul.

## What is Ruul? ##

Ruul is *Fuzzy* *Dynamtic* *Clustering* *Analysis* *Picture* *Tool* developed by
Tokhta Horqin at China University of Geosciences in China, and based on 
模糊数学方法及其应用[M]. 谢季坚, 刘承平. 华中科技大学出版社. 2000

"Uul" (pronounced Ah-Goo-La, spelling уул and ᠠᠭᠤᠯᠠ) means "Mountain" in Mongolian.

## Configure ##

The first, source the setting ( Imports: **Rcpp** ):

    export PKG_LIBS=`Rscript -e "Rcpp:::LdFlags()"`
    export PKG_CXXFLAGS=`Rscript -e "Rcpp:::CxxFlags()"`

The second, build and INSTALL the software:

    R CMD build Ruul && R CMD INSTALL Ruul*.tar.gz

## License ##

Ruul is free software distributed under the terms of the MIT license.

## Information ##

If you have problems, report bugs directly: Tokhta Horqin tokhta@outlook.com

