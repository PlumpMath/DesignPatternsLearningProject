namespace Observer
{
    partial class ObserverForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.buttonDoObserve = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxTimeAsSecond = new System.Windows.Forms.TextBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.watch1_button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonDoObserve
            // 
            this.buttonDoObserve.Location = new System.Drawing.Point(165, 205);
            this.buttonDoObserve.Name = "buttonDoObserve";
            this.buttonDoObserve.Size = new System.Drawing.Size(75, 23);
            this.buttonDoObserve.TabIndex = 0;
            this.buttonDoObserve.Text = "Do Observe";
            this.buttonDoObserve.UseVisualStyleBackColor = true;
            this.buttonDoObserve.Click += new System.EventHandler(this.buttonDoObserve_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(28, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(79, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "TimeAsSecond";
            // 
            // textBoxTimeAsSecond
            // 
            this.textBoxTimeAsSecond.Location = new System.Drawing.Point(148, 28);
            this.textBoxTimeAsSecond.Name = "textBoxTimeAsSecond";
            this.textBoxTimeAsSecond.ReadOnly = true;
            this.textBoxTimeAsSecond.Size = new System.Drawing.Size(206, 20);
            this.textBoxTimeAsSecond.TabIndex = 2;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // watch1_button
            // 
            this.watch1_button.Location = new System.Drawing.Point(381, 28);
            this.watch1_button.Name = "watch1_button";
            this.watch1_button.Size = new System.Drawing.Size(75, 23);
            this.watch1_button.TabIndex = 0;
            this.watch1_button.Text = "Watch";
            this.watch1_button.UseVisualStyleBackColor = true;
            this.watch1_button.Click += new System.EventHandler(this.buttonDoObserve_Click);
            // 
            // ObserverForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(540, 261);
            this.Controls.Add(this.textBoxTimeAsSecond);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.watch1_button);
            this.Controls.Add(this.buttonDoObserve);
            this.Name = "ObserverForm";
            this.Text = "Observer";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonDoObserve;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxTimeAsSecond;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button watch1_button;
    }
}

