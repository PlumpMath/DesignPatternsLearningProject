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
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.labelObserveState = new Observer.LabelObserver();
            this.textBoxTimeAsSecond = new Observer.TextboxObserver();
            this.watch1_button = new Observer.ButtonObserver();
            this.SuspendLayout();
            // 
            // buttonDoObserve
            // 
            this.buttonDoObserve.Font = new System.Drawing.Font("Arial", 14F);
            this.buttonDoObserve.Location = new System.Drawing.Point(183, 194);
            this.buttonDoObserve.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.buttonDoObserve.Name = "buttonDoObserve";
            this.buttonDoObserve.Size = new System.Drawing.Size(128, 41);
            this.buttonDoObserve.TabIndex = 0;
            this.buttonDoObserve.Text = "Do Observe";
            this.buttonDoObserve.UseVisualStyleBackColor = true;
            this.buttonDoObserve.Click += new System.EventHandler(this.buttonDoObserve_Click);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // labelObserveState
            // 
            this.labelObserveState.AutoSize = true;
            this.labelObserveState.Font = new System.Drawing.Font("Microsoft Sans Serif", 30F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelObserveState.Location = new System.Drawing.Point(162, 105);
            this.labelObserveState.Name = "labelObserveState";
            this.labelObserveState.Size = new System.Drawing.Size(173, 46);
            this.labelObserveState.TabIndex = 3;
            this.labelObserveState.Text = "Standby";
            // 
            // textBoxTimeAsSecond
            // 
            this.textBoxTimeAsSecond.Location = new System.Drawing.Point(125, 37);
            this.textBoxTimeAsSecond.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.textBoxTimeAsSecond.Name = "textBoxTimeAsSecond";
            this.textBoxTimeAsSecond.ReadOnly = true;
            this.textBoxTimeAsSecond.Size = new System.Drawing.Size(240, 22);
            this.textBoxTimeAsSecond.TabIndex = 2;
            // 
            // watch1_button
            // 
            this.watch1_button.Enabled = false;
            this.watch1_button.Location = new System.Drawing.Point(384, 26);
            this.watch1_button.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.watch1_button.Name = "watch1_button";
            this.watch1_button.Size = new System.Drawing.Size(87, 45);
            this.watch1_button.TabIndex = 0;
            this.watch1_button.Text = "Do Watch";
            this.watch1_button.UseVisualStyleBackColor = true;
            this.watch1_button.Click += new System.EventHandler(this.watch1_button_Click);
            // 
            // ObserverForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(496, 321);
            this.Controls.Add(this.labelObserveState);
            this.Controls.Add(this.textBoxTimeAsSecond);
            this.Controls.Add(this.watch1_button);
            this.Controls.Add(this.buttonDoObserve);
            this.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "ObserverForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Observer";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonDoObserve;
        private TextboxObserver textBoxTimeAsSecond;
        private System.Windows.Forms.Timer timer1;
        private ButtonObserver watch1_button;
        private LabelObserver labelObserveState;
    }
}

