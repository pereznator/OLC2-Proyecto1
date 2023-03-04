%option reentrant noyywrap nounput batch yylineno
%option debug

%{
    /* se convierte con: flex --verbose lexer.y*/
    #include <iostream>
    //Este metodo define el yylex para pullear tokens, lo unico que vamos a cambiar va a ser el ultimo parametro
    //y le pondremos el nombre de nuestra clase que usamos para analizar la entrada
    #define YY_DECL yy::Parser::symbol_type yylex(yyscan_t yyscanner, yy::location& loc, class MiniOlc::ParserCtx & ctx)
    // todo esto no lo tocamos
    #define YY_USER_ACTION loc.columns(yyleng);
    #define yyterminate() return Parser::make_END(loc)
    #include "parser.hpp"
    #include "ast.h"
    using namespace yy;
    //typedefs (abreviaturas DefLarga DefCorta) para definiciones de tokens
    typedef yy::Parser::token token;
    typedef yy::Parser::token_type token_type;
/// código adicinoal aquí

%}

/* ============== INICIO DE SCANNER ==========  */


/* expresiones regulares */

DIGITO [0-9]
LETRAS [a-zA-ZñÑ]
NUMERO {DIGITO}+
ID  {LETRAS}({DIGITO}|{LETRAS}|"_")*
comentarioLineal ("/""/".*)
comentarioMulti ("/"\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*"/")

%%

%{
// inicia la lectura
    loc.step();
%}

    /* inicia la defincion de tokens   */


    /* caracteres ignorados */

"//"[^\n]*\n            ; /* comentarios de una linea */

[\n]       {
        loc.step();
}

[ \t\v\r\f]             ; /* caracteres en blanco */
    /* Lexemas */
    /* defincion moderna
        token::ID ID sin caracteres especiales
    */
{comentarioLineal} ;
{comentarioMulti}  ;
"evaluar"     return Parser::symbol_type( token::EVALUAR, loc );
"+"     return Parser::symbol_type( token::SUMA, loc );
"-"     return Parser::symbol_type( token::MENOS, loc );
"("     return Parser::symbol_type( token::PARIZQ, loc );
")"     return Parser::symbol_type( token::PARDER, loc );

    /* defincion clásica / para caracteres especiales */
";"     return Parser::symbol_type( token::PYCOMA, loc );
"*"     return Parser::symbol_type( token::POR, loc );
"/"     return Parser::symbol_type( token::DIVIDIDO, loc );


    /* TOKENS  */

{ID}  return Parser::make_ID(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
.  {

        /*std::cerr<<loc <<": "<<"error token no esperado"<<  std::endl;*/
            MiniOlc::AST::getAST()->listaErrores += "token no esperado: ";
            MiniOlc::AST::getAST()->listaErrores += yytext;
            MiniOlc::AST::getAST()->listaErrores += " en la linea ";
            MiniOlc::AST::getAST()->listaErrores +=  std::to_string(yylineno);

            MiniOlc::AST::getAST()->listaErrores += "\n";

        }



    /*si no se usa yyterminate() se agrega lo siguiente*/
    /* <<EOF>> {return Parser::make_END(loc);} */

%%
