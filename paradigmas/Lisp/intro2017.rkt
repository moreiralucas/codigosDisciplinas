#lang racket

(define l1 '(a b c d e a a a b b b))

(define l2 '(((ra a) b d a) (fd s (www b)) (d (a))))

(define l3 '(a b))

(define l5 '(a a a b b b c c c a a d d d d d d))

(define l7 '(a a a b b b c c c a a d d d d d d a b c))

(define p1 '(a . b))

(define sqr1 (lambda(x) (* x x)))

(define (sqr2 x) (* x x))

(define (f a) (* a a))

(define (soma-n l)
  (if (null? l)
      0
      (+ (first l) (soma-n (rest l)))))

(define (soma2-n l) (sn2-l l 0))

(define (sn2-l l a)
  (if (null? l)
      a
      (sn2-l (rest l) (+ (first l) a))))

(define (atom? a)
  (not (list? a)))

(define (atom1? a)
  (not (or (pair? a) (null? a))))



(define (sn l)
  (if (null? l)
      0
      (+ (first l) (sn (rest l)))))

(define (rmembro x l)
  (cond
    [(null? l) '()]
    [(eq? x (first l)) (rest l)]
    [else (cons (first l)
                (rmembro x (rest l)))]
    ))


(define (rmembro* x l)
  (cond
    [(null? l) '()]
    [(eq? x (first l)) (rmembro* x (rest l))]
    [else (cons (first l)
                (rmembro* x (rest l)))]
    ))


(define (substitui x y l)
  (cond
    [(null? l) '()]
    [(eq? x (first l)) (cons y (substitui x y (rest l)))]
    [else (cons (first l)
                (substitui x y (rest l)))]
    ))


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


(define (intercala e1 e2 n)
  (if (< n 1)
      '()
      (cons e1 (intercala e2 e1 (- n 1)))))



(define (fpe e1 l1 lae)
  (cond
   [(null? l1) (cons lae l1)]
   [(not (eq? e1 (first l1))) (cons lae l1)]
   [else (fpe e1 (rest l1) (cons (first l1) lae))]
   ))
 
(define (empacote l)
  (cond
    [(null? l) '()]
    [else
        (let ([lr (fpe (first l) l '())])
            (cons (first lr) (empacote (rest lr))))]
    ))


(define (contagem-inv n)
  (if (< n 1)
      '()
      (cons n (contagem-inv (- n 1)))))

(define (contagem n [la '()])
  (if (< n 1)
      la
      (contagem (- n 1) (cons n la))))
