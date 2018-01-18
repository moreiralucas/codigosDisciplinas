#lang racket

(define l1 '(a b c d e a a a b b b))

(define l2 '(((ra a) b d a) (fd s (www b)) (d (a))))
(define l22 '(((ra a) b d a) (fd s (www b)) (d (a))))
(define l23 '(((ra a) b d a) (fd (www b)) (d (a))))

(define l3 '(a b))

(define l4 '(a b c (1 2 3) d))

(define l5 '(a a a b b b c c c a a d d d d d d))

(define l7 '(a a a b b b c c c a a d d d d d d a b c))

(define l8 '(1 2))

(define l9 '(1 2))

(define l10 '((1 2 3) (1 2 3 4) (1 2) (1)))

(define p1 '(a . b))

(define sqr1 (lambda(x) (* x x)))

(define (membro*? a l)
  (cond
    [(null? l) #f]
    [(list? (first l)) (or (membro*? a (first l))
                           (membro*? a (rest l)))]
    [(eq? a (first l)) #t]
    [else (membro*? a (rest l))]
   ))

(define (rmember* a l)
	(cond
	  [(null? l) '()]
	  [(list? (first l))
              (cons
               (rmember* a (first l))
               (rmember* a (rest l)))]
         [(eq? a (first l)) (rmember* a (rest l))]
         [else (cons (first l) (rmember* a (rest l)))]
      ))


(define (reverse* lg)
  (r* lg '()))

(define (r* lg acc)
  (cond
    [(null? lg) acc]
    [(list? (first lg))
         (r* (rest lg) (cons (r* (first lg) '()) acc))]
    [else (r* (rest lg) (cons (first lg) acc))]
    ))

(define (iguais l1 l2)
  (cond
    [(and (null? l1) (null? l2)) #t]
    [(null? l1) #f]
    [(null? l2) #f]
    [(not (eq? (first l1) (first l2))) #f]
    [else
     (iguais (rest l1) (rest l2))]
    ))


(define (iguais* l1 l2)
  (cond
    [(and (null? l1) (null? l2)) #t]
    [(null? l1) #f]
    [(null? l2) #f]
    [(and (list? (first l1)) (list? (first l2)))
            (and (iguais* (first l1) (first l2))
                 (iguais* (rest l1) (rest l2)))]
    [(list? (first l1)) #f]
    [(list? (first l2)) #f]
    [else
            (and (eq? (first l1) (first l2))
                 (iguais* (rest l1) (rest l2)))]
    ))
     

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
    ))
     
;;;;;;;;;;;;;;;;;;;;;
; Quick Sort
;;;;;;;;;;;;;;;;;;;;;

;;;;
; Função filtro
; Baseado no pivô p, separa a lista l em duas listas:
; l1 contendo todos os elementos de l que são menores que p
; l2 todos os elementos de l que NÃO são menores que p
; retorna o par l1/l2, ou seja (cons l1 l2)

(define (filtro p l [l1 '()] [l2 '()])
  (cond
    [(null? l) (cons l1 l2)]
    [(< (first l) p)
         (filtro p (rest l) (cons (first l) l1) l2)]
    [else
         (filtro p (rest l) l1 (cons (first l) l2))]))

;;;;
; qs
; função de ordenação quick sort básica
; ordena uma lista l de números

(define (qs l)
  (cond
    [(null? l) l]
    [(null? (rest l)) l]
    [else (let ([r (filtro (first l) (rest l))])
            (append
                (qs (first r))
                (cons (first l) (qs (rest r)))))]))

  
;;;;
; Quick Sort Genérico
;
; recebe lista para ordenar - l
; #:f é a função de comparação (default <)
; #:k é a função de extração da chave (default identity) 

(define (qsg l #:f [f <] #:k [k identity])
  (cond
    [(null? l) l]
    [(null? (rest l)) l]
    [else (let ([r (filtrog (first l) (rest l) #:f f #:c k)])
            (append
                (qsg (first r) #:f f #:k k)
                (cons (first l) (qsg (rest r) #:f f #:k k))))]))


;;;;
; Função filtrog
;
; Baseado no pivô p, separa a lista l em duas listas:
; l1 contendo todos os elementos de l que são "menores" que p
; l2 todos os elementos de l que NÃO são "menores" que p
; retorna o par l1/l2, ou seja (cons l1 l2)
;
; O Conceito de "menor" é determinado por #:f e #:c
; #:f é a função de comparação (default <)
; #:c é a função de extração da chave (default identity) 

(define (filtrog p l [l1 '()] [l2 '()] 
                 #:f [funcao <] 
                 #:c [chave identity])
  (cond
    [(null? l) (cons l1 l2)]
    [(funcao (chave (first l)) (chave p))
         (filtrog p (rest l) (cons (first l) l1) l2 
                  #:f funcao
                  #:c chave)]
    [else
         (filtrog p (rest l) l1 (cons (first l) l2)
                  #:f funcao
                  #:c chave)]))

