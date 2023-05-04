// Generated from com\mycompany\analisador\semantico\Gyh.g4 by ANTLR 4.7.2
package com.mycompany.analisador.semantico;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link GyhParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface GyhVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link GyhParser#programa}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrograma(GyhParser.ProgramaContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#listaDeclaracoes}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitListaDeclaracoes(GyhParser.ListaDeclaracoesContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#declaracao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclaracao(GyhParser.DeclaracaoContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#tipoVar}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTipoVar(GyhParser.TipoVarContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#expressaoAritmetica}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressaoAritmetica(GyhParser.ExpressaoAritmeticaContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#termoAritmetico}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTermoAritmetico(GyhParser.TermoAritmeticoContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#fatorAritmetico}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFatorAritmetico(GyhParser.FatorAritmeticoContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#expressaoRelacional}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressaoRelacional(GyhParser.ExpressaoRelacionalContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#termoRelacional}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTermoRelacional(GyhParser.TermoRelacionalContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#operadorBooleano}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOperadorBooleano(GyhParser.OperadorBooleanoContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#listaComandos}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitListaComandos(GyhParser.ListaComandosContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#comando}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComando(GyhParser.ComandoContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#comandoAtribuicao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComandoAtribuicao(GyhParser.ComandoAtribuicaoContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#comandoEntrada}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComandoEntrada(GyhParser.ComandoEntradaContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#comandoSaida}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComandoSaida(GyhParser.ComandoSaidaContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#comandoCondicao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComandoCondicao(GyhParser.ComandoCondicaoContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#comandoRepeticao}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComandoRepeticao(GyhParser.ComandoRepeticaoContext ctx);
	/**
	 * Visit a parse tree produced by {@link GyhParser#subAlgoritmo}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSubAlgoritmo(GyhParser.SubAlgoritmoContext ctx);
}