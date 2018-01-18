#lang racket
;Questão 01 - Lista 02
(define (concatena1 l1 l2)
  (cond
    [(null? l2) '()]
    [(null? l1) (cons (first l2) (concatena1 l1 (rest l2)))]
    [else (cons (first l1) (concatena1 (rest l1) l2))]
   )
)

;Questão 02 - Lista 02
(define (concatenarInv l1 l2)
  (concatena1 l2 l1))

;Questão 03 - Lista 02 - Não funciona corretamente
(define (concatenar2* ll)
  (cond
    [(null? ll) '()]
    [(list? (first ll))
     (cons (concatenar2* (first ll)) (concatenar2* (rest ll)))]
    [else
     (cons (first ll) (concatenar2* (rest ll)))]
  )
)

;Questão 04 - Lista 02
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

;Questão 05 - Lista 02

;Questão 06 - Lista 02
(define (inverte l)
  (inverte-AC l '()))
(define (inverte-AC l a)
  (if (null? l)
      a
      (inverte-AC (rest l) (cons (first l) a))))

;Questão 11 - Lista 02
(define (prefixo l1 l2)
  (cond
    [(and (null? l1) (null? l2)) #t] ;Caso as listas sejam inicialmente nulas
    [(null? l1) #t] ;Considerando que um lista nula é sublista de qualquer lista
    [(null? l2) '()]
    [(eq?(first l1) (first l2))
     (prefixo (rest l1) (rest l2))]
    [else '()]))