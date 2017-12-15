Ruul.fdcp <- function(r) {

    lmd    <- vector()
    xhsz   <- vector()
    flsz   <- vector()
    hxsz   <- vector()
    flrlsz <- matrix(0, nrow = nrow(r), ncol = ncol(r))
    Sz     <- vector()
    Sz0    <- vector()
    Sz1    <- vector()
    n      <- nrow(r)

    for (i in Ruul.gseq(1, n)) {
        r[i, i] <- 1.00
        for (j in Ruul.gseq(1, n)) {
            if (r[i, j] < 0) {
                r[i, j] <- 0
            } 
            if (r[i, j] > 1) {
                r[i, j] <- 1
            }
            r[i, j] <- round(r[i, j] * 100) / 100
        }
    }
    js0 <- 0
    while (TRUE) {
        r1 <- Ruul.comm(r, r)
        if (all(abs(r - r1) < 1E-6)) {
            break
        } else {
            r <- r1
        }
    }
    lmd[1] <- 1
    k <- 1
    for (i in Ruul.gseq(1, n)) {
        for (j in Ruul.gseq(i + 1, n)) {
            pd <- TRUE
            for (x in Ruul.gseq(1, k)) {
                if (r[i, j] == lmd[x]) {
                    pd <- FALSE
                    break
                }
            }
            if (pd) {
                k <- k + 1
                lmd[k] <- r[i, j]
            }
        }
    }
    for (i in Ruul.gseq(1, k - 1)) {
        for (j in Ruul.gseq(i + 1, k)) {
            if(lmd[i] < lmd[j]) {
                x <- lmd[j]
                lmd[j] <- lmd[i]
                lmd[i] <- x
            }
        }
    }
    for (x in Ruul.gseq(1, k)) {
        js <- 0
        flsz[x] <- 0
        for (i in seq(1, n)) {
            pd <- TRUE
            for(y in Ruul.gseq(1, js)) {
                if(Sz[y] == i) {
                    pd <- FALSE
                    break
                }
            }
            if (pd) {
                for (j in Ruul.gseq(1, n)) {
                    if (r[i, j] >= lmd[x]) {
                        js <- js + 1
                        Sz[js] <- j
                    }
                }
                flsz[x] <- flsz[x] + 1
            }
        }
    }
    for (i in Ruul.gseq(1, k - 1)) {
        for (j in Ruul.gseq(i + 1, k)) {
            if (flsz[j] == flsz[i]) {
                flsz[j] <- 0
            }
        }
    }
    fl <- 0
    for (i in Ruul.gseq(1, k)) {
        if (flsz[i] != 0) {
            fl <- fl + 1
            lmd[fl] <- lmd[i]
        }
    }
    for (i in Ruul.gseq(1, n)) {
        xhsz[i] <- i
    }
    for (x in Ruul.gseq(1, fl)) {
        js <- 0
        flsz[x] <- 0
        for (i in Ruul.gseq(1, n)) {
            pd <- TRUE
            for (y in Ruul.gseq(1, js)) {
                if (Sz[y] == i) {
                    pd = FALSE
                    break
                }
            }
            if (pd) {
                if (js == 0) {
                    y <- 0
                }
                for (j in Ruul.gseq(1, n)) {
                    if (r[i, j] >= lmd[x]) {
                        js <- js + 1
                        Sz[js] <- j
                    }
                }
                flsz[x] <- flsz[x] + 1
                Sz0[flsz[x]] <- js - y
            }
        }
        js0 <- 0
        for (i in Ruul.gseq(1, flsz[x])) {
            for (j in Ruul.gseq(1, Sz0[i])) {
                Sz1[j] <- Sz[js0 + j]
            }
            for (j in Ruul.gseq(1, n)) {
                for (y in Ruul.gseq(1, Sz0[i])) {
                    if (xhsz[j] == Sz1[y]) {
                        js0 <- js0 + 1
                        Sz[js0] <- xhsz[j]
                    }
                }
            }
        }
        for (i in Ruul.gseq(1, n)) {
            xhsz[i] <- Sz[i]
        }
    }
    for (x in Ruul.gseq(1, fl)) {
        js <- 0
        flsz[x] <- 0
        for (i in Ruul.gseq(1, n)) {
            pd <- TRUE
            for (y in Ruul.gseq(1, js)) {
                if (Sz[y] == i) {
                    pd <- FALSE
                    break
                }
            }
            if (pd) {
                if (js == 0) {
                    y <- 0
                }
                for (j in Ruul.gseq(1, n)) {
                    if (r[i, j] >= lmd[x]) {
                        js <- js + 1
                        Sz[js] <- j
                    }
                }
                flsz[x] <- flsz[x] + 1
                Sz0[flsz[x]] <- js - y
            }
        }
        js0 <- 1
        for (i in Ruul.gseq(1, flsz[x])) {
            y <- 1
            for (j in Ruul.gseq(1, flsz[x])) {
                if (Sz[y] == xhsz[js0]) {
                    flrlsz[x, i] <- Sz0[j]
                    js0 <- js0 + Sz0[j]
                    break
                }
                y <- y + Sz0[j]
            }
        }
    }
    NU <- 15
    plot.new()
    plot.window(xlim = c(0, 1000), ylim = c(0, 1000))
    Kd <- 30
    Gd <- 40
    if (n < 20) {
        lx <- 60
    } else {
        lx <- 80
    }
    if (flsz[1] == n) {
        y <- fl * Gd + Gd
        text(24, y + Gd / 2 + 8, expression(lambda))
        for (i in Ruul.gseq(1, n)) {
            text(lx - 5 + i * Kd - 0.4 * Kd + NU, y + Gd / 2 + 8, xhsz[i])
            lines(c(lx + i * Kd, lx + i * Kd), c(y, y - Gd))
            hxsz[i] <- lx + i * Kd
        }
        text(lx * i * Kd, y + Gd / 2 + 8, "CN")
        js0 <- 1
        js1 <- 0
        text(16, y - Gd / 2, "1.0000")
        for (i in Ruul.gseq(1, flsz[1])) {
            js1 <- flrlsz[1, i] - 1
            if (js1 != 0) {
                lines(c(hxsz[js0], 1 + hxsz[js0 + js1]), c(y, y))
            }
            lines(c((hxsz[js0 + js1] + hxsz[js0]) / 2, (hxsz[js0 + js1] + hxsz[js0]) / 2), c(y, y - Gd))
            hxsz[i] <- (hxsz[js0 + js1] + hxsz[js0]) / 2
            js0 <- js0 + js1 + 1
        }
        text(lx * 1.5 + n * Kd, y - Gd / 2, flsz[1])
    } else {
        y <- fl * Gd
        text(24, y, expression(lambda))
        for (i in Ruul.gseq(1, n)) {
            text(lx - 5 + i * Kd - 0.4 * Kd + NU, y, xhsz[i])
            lines(c(lx + i * Kd, lx + i * Kd), c(y - Gd / 4, y - Gd / 2))
            hxsz[i] <- lx + i * Kd
        }
        text(lx * 1.5 + n * Kd, y, "CN")
        js0 <- 1
        js1 <- 0
        y <- y - Gd / 2
        text(16, y - Gd / 2, "1.0000")
        for (i in Ruul.gseq(1, flsz[1])) {
            js2 <- 0
            js1 <- js1 + flrlsz[1, i]
            for (j in Ruul.gseq(1, n)) {
                js2 <- js2 + 1
                if (js2 == js1) {
                    break
                }
            }
            if (j != js0) {
                lines(c(hxsz[js0], 1 + hxsz[j]), c(y, y))
            }
            lines(c(((hxsz[js0] + hxsz[j]) / 2), (hxsz[js0] + hxsz[j]) / 2), c(y, y - Gd))
            hxsz[i] <- (hxsz[js0] + hxsz[j]) / 2
            js0 <- j + 1
        }
        text(lx * 1.5 + n * Kd + y - Gd / 2, flsz[1])
    }
    for (x in Ruul.gseq(2, fl)) {
        js0 <- 1
        js1 <- 0
        y <- y - Gd
        text(16, y - Gd / 2, lmd[x])
        for (i in Ruul.gseq(1, flsz[x])) {
            js2 <- 0
            js1 <- js1 + flrlsz[x, i]
            for (j in Ruul.gseq(1, flsz[x - 1])) {
                js2 <- js2 + flrlsz[x - 1, j]
                if (js2 == js1) {
                    break
                }
            }
            if (j != js0) {
                lines(c(hxsz[js0], 1 + hxsz[j]), c(y, y))
            }
            lines(c((hxsz[js0] + hxsz[j]) / 2, (hxsz[js0] + hxsz[j]) / 2), c(y , y - Gd))
            hxsz[i] <- (hxsz[js0] + hxsz[j]) / 2
            js0 <- j + 1
        }
        text(lx * 1.5 + n * Kd, y - Gd / 2, flsz[x])
    }
}

