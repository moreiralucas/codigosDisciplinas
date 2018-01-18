#lang racket

(define l1 '(a b c d e a a a b b b))

(define l2 '(((ra a) b d a) (fd s (www b)) (d (c a))))

(define l3 '(a . b))

(define l4 '())

(define l5 '(a a a b b b c c c a a d d d d d d))

(define l6 '(1 2 3 4 5 6))
(define l7 '(7 8 9))

(define l8 '((a b) c d (e f)))

(define A1 'abcde)

(define A2 'xyz)

(define (sqr2 a) (* a a))

(define (sqr3 a) (* a (sqr2 a)))

(define (sqr4 a) (* a (sqr3 a)))

(define (atom? x)
  (not (list? x)))

(define (non-atom? a)
  (if (atom? a)
      #f
      #t))

(define sqr1 (lambda(x) (* x x)))

(define (lat? l)
  (cond
    [(null? l) #t]
    [(non-atom? (car l)) #f]
    [else (lat? l)]
    ))

(define (soma-numeros l)
  (if (null? l)
    0
    (+ (first l) (soma-numeros(cdr l))))
)
(define x 4)

(define (soma-num l)
  (if (null? l)
      0
      (+ (first l) (soma-num (rest l)))
  )
)

(define (soma-num2 l)
  (sn2 l 0))
(define (sn2 l a)
  (if (null? l)
      a
      (sn2 (rest l) (+ (first l) a))
  )
)

(define (intercala e1 e2 n)
  (if (< n 1)
      '()
      (cons e1 (intercala e2 e1 (- n 1)))))

(define (mescle l1 l2)
  (cond
    [(null? l1) l2]
    [(null? l2) l1]
    [(< (first l2) (first l1))
     (cons (first l2) (mescle l1 (rest l2)))]
    [else
     (cons (first l1) (mescle (rest l1) l2))]
  )
)
         
(define (return-obo l)
  (if (null? l)
     '()
     (cons (first l) (return-obo (rest l)))
   )
)

(define (concatena1 l1 l2)
  (cond
    [(null? l2) '()]
    [(null? l1) (cons (first l2) (concatena1 l1 (rest l2)))]
    [else (cons (first l1) (concatena1 (rest l1) l2))]
   )
)

(define (concatenarInv l1 l2)
  (concatena1 l2 l1))

; '((a b) (c) (e f g))
(define (concatenar2* ll)
  (cond
    [(null? ll) '()]
    [(list? (first ll))
     (cons (concatenar2* (first ll)) (concatenar2* (rest ll)))]
    [else
     (cons (first ll) (concatenar2* (rest ll)))]
  )
)

(define (iguais2* l1 l2)
  (cond
    [(and (null? l1) (null? l2)) #t]
    [(null? l1) #f]
    [(null? l2) #f]
    [(and (list? (first l1)) (list? (first l2)))
          (if (iguais2* (first l1) (first l2))
              (iguais2* (rest l1) (rest l2))
              #f)]
     [(list? (first l1)) #f]
     [(list? (first l2)) #f]
     [(not (eq? (first l1) (first l2))) #f]
     [else (iguais2* (rest l1) (rest l2))]
   )
)

(define (rmembro a l)
  (cond
    [(null? l) '()]
    [(eq? a (first l)) (rest l)]
    [else
     (cons (first l) (rmembro a (rest l)))]))

(define (troca-n a n l) ; Troca todas ocrrências de 'a por 'n
  (cond
    [(null? l) '()]
    [(eq? a (first l))
     (cons n (troca-n a n (rest l)))]
    [else
     (cons (first l) (troca-n a n (rest l)))]
    )
  )

(define (varre-insert-all new old l)
  (cond
    [(null? l) '()]
    [(eq? (first l) old)
     (cons old (cons new (varre-insert-all new old (rest l))))]
    [else
     (cons (first l) (varre-insert-all new old (rest l)))]))

(define (inverte l)
  (inverte-AC l '()))
(define (inverte-AC l a)
  (if (null? l)
      a
      (inverte-AC (rest l) (cons (first l) a))))

(define (rmembro* a l) ;;Nao funciona como deveria
        (cond
          [(null? l) '()]
          [(list? (first l))
            (cons
               (rmembro* a (first l))
               (rmembro* a (rest l)))]
          [(eq? a (first l)) (rmembro* a (rest l))]
          [else (cons (first l) (rmembro* a (rest l)))]
         )
)                
;(define (adiciona-final a l)
;  (add-fim a l '()))
;(define (add-fim a l tmp)
  ;(cond
    ;[(null? l) a]
    ;[(null? (rest l)) a]
    ;[else (add-fim (rest l) (adiciona-final a (rest l))]
   ; )
  ;)
;(define (addfinal z l)
 ; (cond
  ;  [(null? l) z]
   ; [else (cons (addfinal z (rest l)) z)]))
(define (intercala-duas l1 l2)
  (int-duas l1 l2 0))
(define (int-duas l1 l2 n)
  (cond
    [(null? l1) l2]
    [(null? l2) l1]
    [else (if(eq?(modulo n 2) 0)
             (cons (first l1) (int-duas (rest l1) l2 (+ n 1)))
             (cons (first l2) (int-duas (rest l2) l1 n))
           )
    ]))

(define (prefixo l1 l2)
  (cond
    [(and (null? l1) (null? l2)) #t] ;Caso as listas sejam inicialmente nulas
    [(null? l1) #t] ;Considerando que um lista nula é sublista de qualquer lista
    [(null? l2) '()]
    [(eq?(first l1) (first l2))
     (prefixo (rest l1) (rest l2))]
    [else '()]))

; Contagem crescente
(define (contagem n [a '()])
  (if (> n 0)
      (contagem (- n 1) (cons n a))
      a))

; Contagem decrescente
(define (contagem-dec m n [a '()])
  (if (< m n)
      (contagem-dec (+ m 1) n (cons (+ m 1) a))
      a))

; Concatenar l1 com l2
(define (conc l1 l2)
  (cond
    [(null? l1) l2]
    [(null? l2) l1]
    [else (cons (first l1) (conc (rest l1) l2))]
))

; Aplanar
(define (aplanar LG)
  (cond
    [(null? LG) LG]
    [(list? (first LG))
     (conc (aplanar (first LG)) (aplanar (rest LG)))]
    [else
     (cons (first LG)
           (aplanar (rest LG)))]))

;(adiciona-1 '(1 2 3 4 5 6))
(define (adiciona-1 l)
  (map (lambda(x) (+ x 1)) l))
