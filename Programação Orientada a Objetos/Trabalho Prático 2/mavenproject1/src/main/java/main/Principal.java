package main;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */

/**
 *
 * Grupo:
 * Gabriel Ferreira Pereira - 20.1.4015
 * Lavínia Fonseca Pereira - 19.1.4170
 * Pablo Martins Coelho - 20.1.4113
 */
public class Principal extends javax.swing.JFrame {

    
    ArrayList listaAtual;
    ArrayList<Imovel> getDB() throws FileNotFoundException, IOException{
        ArrayList<Imovel> imoveis = new ArrayList();
        String[] lineP;
        int id_count = 0;
        
        File file = new File("database_imoveis.txt");    
        BufferedReader br = new BufferedReader(new FileReader(file));
        String st;
        while((st=br.readLine()) != null){
            lineP = st.split(";");
            
            if("apartamento".equals(lineP[0])){
                imoveis.add(new Apartamento(id_count,
                                            Float.parseFloat(lineP[1]),
                                            lineP[2],
                                            lineP[3],
                                            lineP[4],
                                            lineP[5],
                                            Integer.parseInt(lineP[6]),
                                            Integer.parseInt(lineP[7]),
                                            Integer.parseInt(lineP[8]),
                                            Integer.parseInt(lineP[9]),
                                            Float.parseFloat(lineP[10]),
                                            lineP[11].equals("1") ? true : false,
                                            lineP[12].equals("1") ? true : false));
            }else if("casa".equals(lineP[0])){
                imoveis.add(new Casa(id_count,
                                            Float.parseFloat(lineP[1]),
                                            lineP[2],
                                            lineP[3],
                                            lineP[4],
                                            lineP[5],
                                            Integer.parseInt(lineP[6]),
                                            Integer.parseInt(lineP[7]),
                                            Integer.parseInt(lineP[8]),
                                            Integer.parseInt(lineP[9]),
                                            lineP[10].equals("1") ? true : false));
            }else if("chacara".equals(lineP[0])){
                imoveis.add(new Chacara(id_count,
                                            Float.parseFloat(lineP[1]),
                                            lineP[2],
                                            lineP[3],
                                            lineP[4],
                                            lineP[5],
                                            Integer.parseInt(lineP[6]),
                                            Integer.parseInt(lineP[7]),
                                            Integer.parseInt(lineP[8]),
                                            lineP[9].equals("1") ? true : false,
                                            lineP[10].equals("1") ? true : false,
                                            lineP[11].equals("1") ? true : false,
                                            lineP[12].equals("1") ? true : false,
                                            lineP[13].equals("1") ? true : false));
            }
            id_count++;
        }
        
        return imoveis;
    }
    
    /**
    * 2- Função para verificar se um proprietário existe na coleção
    */
    Boolean checkProprietario(ArrayList<Imovel> imoveis, String proprietario){
        
        for(int i=0;i<imoveis.size();i++){
            if(imoveis.get(i).getProprietario().equals(proprietario)) return true;
        }
        return false;
    }
    
    /**
    * 3- Função para filtrar imóveis pelo valor
    */
    ArrayList<Imovel> filterValor(ArrayList<Imovel> imoveis, float valor){
        ArrayList<Imovel> response = new ArrayList();
        for(int i=0;i<imoveis.size();i++){
            if(imoveis.get(i).getValor() <= valor){
                response.add(imoveis.get(i));
            }
        }
        
        return response;
    }
    
    /**
    * 4- Função para filtrar imóveis pelo número de quartos
    */ 
    ArrayList<Imovel> filterQuartos(ArrayList<Imovel> imoveis, int quartos){
        ArrayList<Imovel> response = new ArrayList();
        for(int i=0;i<imoveis.size();i++){
            if(imoveis.get(i).getQuartos() >= quartos){
                response.add(imoveis.get(i));
            }
        }
        
        return response;
    }
    
    /**
    * 5- Função para filtrar imóveis pelo tipo
    */
    ArrayList<Imovel> filterTipo(ArrayList<Imovel> imoveis, String tipo){
        ArrayList<Imovel> response = new ArrayList();
        for(int i=0;i<imoveis.size();i++){
            if(tipo.equals("Apartamento") && imoveis.get(i) instanceof Apartamento){
                response.add(imoveis.get(i));
            }
            if(tipo.equals("Casa") && imoveis.get(i) instanceof Casa){
                response.add(imoveis.get(i));
            }
            if(tipo.equals("Chacara") && imoveis.get(i) instanceof Chacara){
                response.add(imoveis.get(i));
            }
        }
        
        Collections.sort(response, Imovel.comparator);
        
        return response;
    }
    
    /**
    * 6- Função para filtrar imóveis pela cidade
    */
    ArrayList<Imovel> filterCidade(ArrayList<Imovel> imoveis, String cidade){
        ArrayList<Imovel> response = new ArrayList();
        for(int i=0;i<imoveis.size();i++){
            if(imoveis.get(i).getCidade().equals(cidade)){
                response.add(imoveis.get(i));
            }
        }
        
        Collections.sort(response, Imovel.comparatorR);
        
        return response;
    }
    
    /**
    * 7- Função que retorna um iterador para cada tipo de imóvel que um proprietário tenha
    */
    ArrayList<Imovel> filterProprietario(ArrayList<Imovel> imoveis, String proprietario){
        ArrayList<Imovel> response = new ArrayList();
        
        for (Iterator<Imovel> iterator = imoveis.iterator(); iterator.hasNext();) {
            Imovel next = iterator.next();
            if(next.getProprietario().equals(proprietario)){
                response.add(next);
            }
        }
        
        
        return response;
    }
    
    void printImoveis(ArrayList<Imovel> imoveis, int tipo){
        try {
            PrintStream stdout = System.out;
            PrintStream fileStream;
            File myObj = new File("log.txt");
            myObj.createNewFile();
            fileStream = new PrintStream("log.txt");
            
            if(tipo == 1){
                System.setOut(fileStream);
            }
            for(int i=0;i<imoveis.size();i++){
                imoveis.get(i).print();
            }
            
            if(tipo == 1){
                System.setOut(stdout);
            }
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    void fillTable(ArrayList<Imovel> imoveis){
        DefaultTableModel model = (DefaultTableModel) table.getModel();
        model.setRowCount(0);
        for(int i=0;i<imoveis.size();i++){
            if(imoveis.get(i) instanceof Casa){
                Casa c = (Casa) imoveis.get(i);
                model.addRow(new Object[]{c.getProprietario(),
                    c.getValor(),
                    c.getQuartos(),
                    c.getRua(),
                    c.getBairro(),
                    c.getCidade(),
                    c.getAndares() + " Andares"});
            }else if(imoveis.get(i) instanceof Apartamento){
                Apartamento a = (Apartamento) imoveis.get(i);
                model.addRow(new Object[]{a.getProprietario(),
                    a.getValor(),
                    a.getQuartos(),
                    a.getRua(),
                    a.getBairro(),
                    a.getCidade(),
                    a.getElevador() ? "Possui elevador" : "Não possui elevador"});
            }else if(imoveis.get(i) instanceof Chacara){
                Chacara c = (Chacara) imoveis.get(i);
                model.addRow(new Object[]{c.getProprietario(),
                    c.getValor(),
                    c.getQuartos(),
                    c.getRua(),
                    c.getBairro(),
                    c.getCidade(),
                    c.getPiscina()? "Possui piscina" : "Não possui piscina"});
            }
        }
    }
    
    /**
     * Creates new form Principal
     */
    public Principal() {
        try {
            initComponents();
            ArrayList<Imovel> imoveis = getDB();
            listaAtual = imoveis;
            fillTable(imoveis);
        } catch (IOException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {
        java.awt.GridBagConstraints gridBagConstraints;

        jPanel1 = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        tf_proprietario = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        tf_quartos = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        cb_tipo = new javax.swing.JComboBox<>();
        jLabel5 = new javax.swing.JLabel();
        tf_cidade = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        tf_preco = new javax.swing.JTextField();
        btn_pesquisa = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jPanel2 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        table = new javax.swing.JTable();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMinimumSize(new java.awt.Dimension(375, 300));

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("Filtros"));
        jPanel1.setToolTipText("");
        jPanel1.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        jPanel1.setMinimumSize(new java.awt.Dimension(540, 130));
        jPanel1.setPreferredSize(new java.awt.Dimension(463, 130));
        jPanel1.setLayout(new java.awt.GridBagLayout());

        jLabel3.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel3.setText("Proprietário:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 10;
        gridBagConstraints.weightx = 0.1;
        jPanel1.add(jLabel3, gridBagConstraints);

        tf_proprietario.setMinimumSize(new java.awt.Dimension(60, 22));
        tf_proprietario.setPreferredSize(new java.awt.Dimension(130, 22));
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.weightx = 0.2;
        jPanel1.add(tf_proprietario, gridBagConstraints);

        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("Quartos:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 10;
        gridBagConstraints.weightx = 0.1;
        jPanel1.add(jLabel1, gridBagConstraints);

        tf_quartos.setMinimumSize(new java.awt.Dimension(60, 22));
        tf_quartos.setPreferredSize(new java.awt.Dimension(130, 22));
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.weightx = 0.2;
        jPanel1.add(tf_quartos, gridBagConstraints);

        jLabel2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel2.setText("Tipo:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 2;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 10;
        gridBagConstraints.weightx = 0.1;
        jPanel1.add(jLabel2, gridBagConstraints);

        cb_tipo.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Todos", "Casa", "Apartamento", "Chacara" }));
        cb_tipo.setPreferredSize(new java.awt.Dimension(130, 22));
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 3;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.weightx = 0.2;
        jPanel1.add(cb_tipo, gridBagConstraints);

        jLabel5.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel5.setText("Cidade:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 10;
        gridBagConstraints.weightx = 0.1;
        jPanel1.add(jLabel5, gridBagConstraints);

        tf_cidade.setMinimumSize(new java.awt.Dimension(60, 22));
        tf_cidade.setPreferredSize(new java.awt.Dimension(130, 22));
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.weightx = 0.2;
        jPanel1.add(tf_cidade, gridBagConstraints);

        jLabel4.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel4.setText("Preço:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 2;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 10;
        gridBagConstraints.weightx = 0.1;
        jPanel1.add(jLabel4, gridBagConstraints);

        tf_preco.setMinimumSize(new java.awt.Dimension(60, 22));
        tf_preco.setPreferredSize(new java.awt.Dimension(130, 22));
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 3;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.weightx = 0.2;
        jPanel1.add(tf_preco, gridBagConstraints);

        btn_pesquisa.setText("Pesquisar");
        btn_pesquisa.setMaximumSize(new java.awt.Dimension(71, 25));
        btn_pesquisa.setMinimumSize(new java.awt.Dimension(71, 25));
        btn_pesquisa.setPreferredSize(new java.awt.Dimension(71, 25));
        btn_pesquisa.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_pesquisaActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 4;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.weightx = 0.1;
        jPanel1.add(btn_pesquisa, gridBagConstraints);

        jButton1.setText("Resetar");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 5;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.weightx = 0.1;
        jPanel1.add(jButton1, gridBagConstraints);

        jButton2.setText("Print arquivo");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 4;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.weightx = 0.1;
        jPanel1.add(jButton2, gridBagConstraints);

        jButton3.setText("Print Terminal");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 5;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.weightx = 0.1;
        jPanel1.add(jButton3, gridBagConstraints);

        getContentPane().add(jPanel1, java.awt.BorderLayout.NORTH);

        jPanel2.setBorder(javax.swing.BorderFactory.createTitledBorder("Imóveis"));
        jPanel2.setPreferredSize(new java.awt.Dimension(400, 359));
        jPanel2.setLayout(new java.awt.BorderLayout());

        table.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Proprietário", "Preço", "Nº quartos", "Rua", "Bairro", "Cidade", "PE"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        table.setMaximumSize(new java.awt.Dimension(32767, 32767));
        table.setMinimumSize(new java.awt.Dimension(23, 23));
        table.setPreferredSize(null);
        jScrollPane1.setViewportView(table);

        jPanel2.add(jScrollPane1, java.awt.BorderLayout.CENTER);

        getContentPane().add(jPanel2, java.awt.BorderLayout.CENTER);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btn_pesquisaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_pesquisaActionPerformed
        try {
            String proprietario = tf_proprietario.getText();
            String cidade = tf_cidade.getText();
            float preco = !tf_preco.getText().equals("") ? Float.parseFloat(tf_preco.getText()) : 0;
            int quartos = !tf_quartos.getText().equals("") ? Integer.parseInt(tf_quartos.getText()) : 0;
            String tipo = (String) cb_tipo.getSelectedItem();
                        
            ArrayList<Imovel> imoveis = getDB();
            if(!proprietario.equals("")) {
                if(checkProprietario(imoveis, proprietario)){
                    imoveis = filterProprietario(imoveis, proprietario);
                }else JOptionPane.showMessageDialog(this,
                    "Proprietário não existe.",
                    "Erro de busca",
                    JOptionPane.INFORMATION_MESSAGE);
            }
            if(!cidade.equals("")) imoveis = filterCidade(imoveis, cidade);
            if(preco > 0) imoveis = filterValor(imoveis, preco);
            if(quartos > 0) imoveis = filterQuartos(imoveis, quartos);
            if(!tipo.equals("Todos")) imoveis = filterTipo(imoveis, tipo);
            listaAtual = imoveis;
            fillTable(imoveis);
            
        } catch (IOException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        } catch (NumberFormatException nfe){
            JOptionPane.showMessageDialog(this,
                    "Dado inválido.",
                    "Erro formatação",
                    JOptionPane.ERROR_MESSAGE);
        }
    }//GEN-LAST:event_btn_pesquisaActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        try {
            ArrayList<Imovel> imoveis = getDB();
            fillTable(imoveis);
            tf_cidade.setText("");
            tf_preco.setText("");
            tf_proprietario.setText("");
            tf_quartos.setText("");
            cb_tipo.setSelectedIndex(0);
        } catch (IOException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        printImoveis(listaAtual, 1);
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        printImoveis(listaAtual, 0);
    }//GEN-LAST:event_jButton3ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Principal().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btn_pesquisa;
    private javax.swing.JComboBox<String> cb_tipo;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable table;
    private javax.swing.JTextField tf_cidade;
    private javax.swing.JTextField tf_preco;
    private javax.swing.JTextField tf_proprietario;
    private javax.swing.JTextField tf_quartos;
    // End of variables declaration//GEN-END:variables
}
