## Instruções do Git

**Adicionar no repositório local os arquivos dos repositório externo**
```
git clone endereco
```
Neste caso, substitua a variável "endereco" por https://github.com/moreiralucas/gestaohospital.git

**Use o git fetch para verificar se seu repositorio local está atualizado como repositório externo**
```
git fetch
```

**Descartar mudanças locais (antes do pull)**
```
git checkout -- .
```
(não esqueça do ponto)

**Baixe os arquivos**
```
git pull
```

**Olhe o status**
```
git status
```

**Selecione os arquivos para serem "comitados"**
```
git add -A
```

**Olhe o status**
```
git status
```

**Faça o commit**
```
git commit -m "Descrição"
```

**Alinhe seu "commit" com o servidor externo**
```
git push origin master
```

**Olhe o status**
```
git status
```
