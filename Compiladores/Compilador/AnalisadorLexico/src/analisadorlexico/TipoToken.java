package analisadorlexico;

public enum TipoToken { //define todos os tipos de tokens
    PCDec, PCProg, PCInt, PCReal, PCLer, 
    PCImprimir, PCSe, PCEntao,PCSenao, PCEnqto, PCIni, PCFim,EOF,
    OpAritMult, OpAritDiv, OpAritSoma, OpAritSub, OpRelMenor, OpRelMenorIgual, 
    OpRelMaior, OpRelMaiorIgual, OpRelIgual, OpRelDif,
    OpBoolE, OpBoolOu, Delim, Atrib, AbrePar, FechaPar,
    Var, NumInt,NumReal, Cadeia
}
